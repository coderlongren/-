#include <stdio.h>
#include <time.h>
#include <string.h>
int tree[1<<20];
int main()
{
	int i;
	int m, n;//树的深度  小球数目 
	memset(tree,0,sizeof(tree));
	printf("输入 树的深度 和 小球数目 \n");
	scanf("%d %d",&m, &n);
	int x = (1<<m) - 1;
	int k;
	for (i = 0; i < n; i++)
	{
		k = 1;
		for (;;)
		{
			tree[k] = !tree[k];
			k = tree[k] ? 2*k : 2*k - 1;//判断是下一支 左边还是右边的
			if (k > x) //越界 结束循环 
			{
				break;
			}
		}
	}
	printf("最后一个小球的编号是: %d \n",k/2);
	return 0;
}