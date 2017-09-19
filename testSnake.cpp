#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

const int W = 52;//��ͼ�Ŀ��
const int H = 22;//��ͼ�ĸ߶�

char map[22][52];//��ͼ�Ĵ�С
char key;//�����û�����ʱ�� ����ļ�
int direct = 4;//�ʼ ���˶��ķ������� ����1H   �� 2P �� 3K �� 4M 
int food[2] = {9,11};//food[0]��ʳ��ĺ����� food[1]�� ������
int head;//�ߵĳ���
int snake[900][3];//�ߵ���������� �Լ��ߵ�����:snake[0] = 0  ��ͷ:snake[0] = 1
void init(char map[22][52],int snake[900][3]);//��Ϸ��ʼ��ʱ���ʼ��
void makeMap(char map[22][52],int snake[900][3],int food[2]);//����move() ֮����ߺ����ɵ�foodʳ�����map
void move(int snake[900][3],int direct);//�����ƶ�
void showView(char map[22][52]);//����map
int ifEat(int head,int food[2]);//�ж�ʳ���Ƿ񱻳Ե�
int ifRepeat(int snake[900][3],int x,int y);//�ж����ɵ�ʳ�� �Ƿ�������ظ�
int ifBump(int head);//�Ƿ�ײǽ ����ײ�����ߵ�����
void makeFood(int food[2]);//ͨ�����������һ�� ʳ�������
void getKey();//��ȡ��������ļ� �����·���

int main()
{
	init(map,snake);
	while(true)
	{
		system("cls");//ˢ�¿���̨��Ļ
		Sleep(40);
		move(snake,direct);//��������ƶ�һ�� 
		if (!food[0] && !food[1])//ʳ�ﱻ�Ե� ������һ��ʳ��
		{
			makeFood(food);//����ʳ��
		}
		makeMap(map,snake,food);
		showView(map);
		if (ifBump(head))//�Ƿ�ײ���Լ�����ǽ
		{
			printf("game over your score is %d  ",head);
			break;
		}
		getKey();

	}
	
	return 0;

}
void init(char map[22][52],int snake[900][3])
{
	//��ʼ��snake
	//sanke[i][0] = 0��������  snake[i][0] = 1 ������ͷ snake[i][1] ������ snake[i][2] ������
	snake[0][0] = 0,snake[0][1] = 5,snake[0][2] = 2;
	snake[1][0] = 0,snake[1][1] = 5,snake[1][2] = 3;
	snake[2][0] = 1,snake[2][1] = 5,snake[2][2] = 4;
	//��ʼ��map
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (i == 0 || j == 0 || i ==H - 1 || j == W - 1)
			{
				map[i][j] = '#';
			}
			else
			{
				map[i][j] = ' ';
			}
		}
	}
}

void showView(char map[22][52])
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}

void makeMap(char map[22][52],int snake[900][3],int food[2])
{	int k;
	//�����»���һ���ͼ
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (i == 0 || j == 0 || i == H - 1 || j == W - 1)
			{
				map[i][j] = '#';
			}
			else
			{
				map[i][j] = ' ';
			}
		}
	}
	//���ߵ���״ ���뵽map��ȥ
	for (k = 0; k < 900; k++)
	{
		if (snake[k][0] == 1)//������ͷ
		{
			break;
		}
		map[snake[k][1]][snake[k][2]] = '@';
	}

	map[snake[k][1]][snake[k][2]] = '@';
	map[food[0]][food[1]] = '*';


}

void move(int snake[900][3],int direct)
{
	int x,y;//���ڴ洢��ͷ�� ����
	for (int i = 0; i < 900; i ++)
	{
		if (snake[i][0] == 1)
		{
			head = i;
			break;
		}
	}
	x = snake[head][1];
	y = snake[head][2];
	switch(direct)
	{
		case 1://����
		{
			snake[head][1]--;//��ͷ���������һ
		}
		case 2:
		{
			snake[head][1]++;//��ͷ���������һ
		}
		case 3:
		{
			snake[head][2]--;
		}
		case 4:
		{
			snake[head][2]++;
		}
	}
	//��ͷ�Ѿ�������һ��λ���� ���ж��Ƿ�Ե���ʳ��  ���ߵ�������ǰ�ƶ�һλ
	if (ifEat(head,food))
	{
		snake[head + 1][0] = 1;
		snake[head + 1][1] = food[0];
		snake[head + 1][2] = food[1];
		snake[head][0] = 0;//ȡ����֮ǰ����ͷ
		food[0] = 0;
		food[1] = 0;
	}
	for (int j  = head - 1; j >= 0; j--)
	{
		int temp;
		temp = x,x = snake[j][1],snake[j][1] = temp;
		temp = y,y = snake[j][2],snake[j][2] = temp;
	}
	
}

void makeFood(int food[2])
{
	srand(time(0));//�������
	int x = rand()%50 + 1;
	int y = rand()%20 + 1;
	while (ifRepeat(snake,x,y))
	{
		x = rand()%50 + 1;
		y = rand()%20 + 1;
	}
	food[0] = y;
	food[1] = x;
} 
int  ifEat(int head,int food[2])
{
	if (snake[head][1] == food[0] && snake[head][2] == food[1])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int ifRepeat(int snake[900][3],int x,int y)
{
	for (int i = 0; i < 900; i++)
	{
		if (snake[i][0] == 1)
		{
			break;
		}
		if (snake[i][1] == x && snake[i][2] == y)
		{
			return 1;
		}
	}
	return 0;
}
int ifBump(int head)
{
	//ײǽ
	if (snake[head][1] == 0 || snake[head][1] == 21 || snake[head][2] == 0 || snake[head][2] == 51)
	{
		return 1;
	}
	for (int i = 0; i < head - 1; i++)
	{
		if (snake[i][1] == snake[head][1] && snake[i][2] == snake[head][2])
		{
			return 1;
		}
	}
	return 0;
}
void getKey()
{
	if (_kbhit())
	{
		key = _getch();
	}
	switch (key)
	{
		case 'H':
			{
				if (direct != 2)
				{
					direct = 1;
				}
			}
		case 'P':
			{
				if (direct != 1)
				{
					direct = 2;
				}
			}
		case 'K':
			{
				if (direct != 4)
				{
					direct = 3;

				}
			}
		case 'M':
			{
				if (direct != 3)
				{
					direct = 4;
				}
			}
	}
}