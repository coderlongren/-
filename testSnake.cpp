#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

const int W = 52;//地图的宽度
const int H = 22;//地图的高度

char map[22][52];//地图的大小
char key;//保存用户操作时候 输入的键
int direct = 4;//最开始 蛇运动的方向向右 ，上1H   下 2P 左 3K 右 4M 
int food[2] = {9,11};//food[0]是食物的横坐标 food[1]是 纵坐标
int head;//蛇的长度
int snake[900][3];//蛇的所有坐标点 以及蛇的身体:snake[0] = 0  蛇头:snake[0] = 1
void init(char map[22][52],int snake[900][3]);//游戏开始的时候初始化
void makeMap(char map[22][52],int snake[900][3],int food[2]);//根据move() 之后的蛇和生成的food食物更改map
void move(int snake[900][3],int direct);//让蛇移动
void showView(char map[22][52]);//绘制map
int ifEat(int head,int food[2]);//判断食物是否被吃掉
int ifRepeat(int snake[900][3],int x,int y);//判断生成的食物 是否和蛇有重复
int ifBump(int head);//是否撞墙 或者撞到了蛇的身体
void makeFood(int food[2]);//通过随机数制作一个 食物的坐标
void getKey();//读取键盘输入的键 设置新方向

int main()
{
	init(map,snake);
	while(true)
	{
		system("cls");//刷新控制台屏幕
		Sleep(40);
		move(snake,direct);//蛇向后面移动一下 
		if (!food[0] && !food[1])//食物被吃掉 再生成一个食物
		{
			makeFood(food);//生成食物
		}
		makeMap(map,snake,food);
		showView(map);
		if (ifBump(head))//是否撞到自己或者墙
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
	//初始化snake
	//sanke[i][0] = 0代表蛇身  snake[i][0] = 1 代表蛇头 snake[i][1] 横坐标 snake[i][2] 纵坐标
	snake[0][0] = 0,snake[0][1] = 5,snake[0][2] = 2;
	snake[1][0] = 0,snake[1][1] = 5,snake[1][2] = 3;
	snake[2][0] = 1,snake[2][1] = 5,snake[2][2] = 4;
	//初始化map
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
	//再重新绘制一遍地图
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
	//把蛇的形状 加入到map中去
	for (k = 0; k < 900; k++)
	{
		if (snake[k][0] == 1)//到了蛇头
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
	int x,y;//用于存储蛇头的 坐标
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
		case 1://向上
		{
			snake[head][1]--;//蛇头的纵坐标减一
		}
		case 2:
		{
			snake[head][1]++;//蛇头的纵坐标加一
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
	//蛇头已经到了下一个位置了 先判断是否吃掉了食物  把蛇的身体往前移动一位
	if (ifEat(head,food))
	{
		snake[head + 1][0] = 1;
		snake[head + 1][1] = food[0];
		snake[head + 1][2] = food[1];
		snake[head][0] = 0;//取消了之前的蛇头
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
	srand(time(0));//随机种子
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
	//撞墙
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