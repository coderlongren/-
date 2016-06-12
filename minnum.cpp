#include <stdio.h>
void main()
{
	int m, n, r, temp,f,m1,n1;
	printf("两个数为: \n");
	scanf("%d%d",&m,&n);
	m1 = m;
	n1 = n;
	if (m > n)
	{
		temp = m;
		m = n;
		n = temp;
	}
	f = m*n;
	while (m != 0)
	{
		r = n%m;
		n = m;
		m = r;
	}
	printf("%d and %d 最小公倍数 为 :%d \n", m1, n1, f/n);

}
