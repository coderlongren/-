#include <stdio.h>
#include <time.h>
#include <string.h>
int tree[1<<20];
int main()
{
	int i;
	int m, n;//�������  С����Ŀ 
	memset(tree,0,sizeof(tree));
	printf("���� ������� �� С����Ŀ \n");
	scanf("%d %d",&m, &n);
	int x = (1<<m) - 1;
	int k;
	for (i = 0; i < n; i++)
	{
		k = 1;
		for (;;)
		{
			tree[k] = !tree[k];
			k = tree[k] ? 2*k : 2*k - 1;//�ж�����һ֧ ��߻����ұߵ�
			if (k > x) //Խ�� ����ѭ�� 
			{
				break;
			}
		}
	}
	printf("���һ��С��ı����: %d \n",k/2);
	return 0;
}