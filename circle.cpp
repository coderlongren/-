/*  对小球的 排序： 输入小球个数 ；  A 3 5 把三号位的小球移动到 5号位的左边； B 2 3 把二号位的小球移动到三号位的 右边  */
#include <iostream>
#include <time.h>
using namespace std;
//int find()
int main()
{
	char type[6];//指令
	int X, Y;//小球的 初始位置
	int p, q;// small ball 在数组中的位置 
	int i, j, m, n;
	cout<<"input num_balls\n";
	cin>>n;
	cout<<"input conduct num \n";
	cin>>m;
	int ball[1000];
	for (i = 1; i <= n; i++)
	{
		ball[i] = i;
	}
	for (i = 0; i < m; i++)
	{
		cout<<"type: ";
		cin>>type;
		cout<<"X and Y :\n";
		cin>>X>>Y;
		int count = 1;
		for ( j = 1; j <= n; j++)
		{
			if (ball[j] != X)
			{
				count++;
			}
			else 
			{
				p = count;
				break;
			}
		}
		count = 1;
		for (j = 1; j <= n; j++)
		{
			if (ball[j] != Y)
			{
				count++;
			}
			else
			{
				q = count;
				break;
			}
		}
		cout<<p<<q<<endl;
		if (type[0] == 'A')
		{
			if (q > p) 
			{
				int s = ball[p];
				for (j = (p + 1); j <= (q - 1); j++)
				{
					ball[j - 1] = ball[j];
				}
				ball[q - 1] = s;
			}
			else 
			{
				int s = ball[p];
				for (j = p; j >= (q - 2); j--)
				{
					ball[j] = ball[j-1];
				}
				ball[q - 1] = s;
			}
		}
		if (type[0] == 'B')
		{
			if (q > p)
			{
				int s = ball[p];
				for (j = p; j <= (q - 1); j++)
				{
					ball[j] = ball[j + 1];
				}
				ball[q] = s;
			}
			else 
			{
				int s = ball[q];
				for (j = q; j<= (p - 1); j--)
				{
					ball[j] = ball[j - 1];
				}
				ball[p] = s;
			}
		}
	}
	for (j = 1; j <= n; j++)
	{
		cout<<ball[j]<<" ";
	}
	cout<<endl;
	cout<<"time = "<<(double)clock() / CLOCKS_PER_SEC<<endl;
	return 0;
}