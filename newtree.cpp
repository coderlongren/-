#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define N (1<<20)
int tree[N];
int main()
{
	int i;
	int x = 1;
	int m, n;//���ĵ���� ��С����Ŀ
	memset(tree,0,sizeof(tree));
	cout<<"input the m and n \n";
	cin>>m>>n;
	for (i = 0; i < m - 1; i++)
	{
		if (n % 2 == 1) 
		{
			x = 2 * x;
			n = (n + 1)/2;
		}
		else 
		{
			x = 2 * x + 1;
			n = n/2;
		}
	}
	cout<<"���һ��С�����Ŀ: "<<x<<endl;
	return 0;
}