#include <stdio.h>
#include <stdlib.h>
typedef struct LNode 
{
	int data;
	struct LNode *next;
}LinkList;
void InitList(LinkList *&l)
{
	l = (LinkList *)malloc(sizeof(LinkList));
	l->next = NULL;
}
void CreateList(LinkList *&l,int a[],int n)
{
	LinkList *s,*r;
	int i;
	l = (LinkList *)malloc(sizeof(LinkList));
	r = l;
	for (i = 0; i < n; i++)
	{
		s  = (LinkList *)malloc(sizeof(LinkList))
	}
}
int main()
{
	return 0;
}