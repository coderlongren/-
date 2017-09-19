#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

void createBTNode(BTNode *&b,char *str);
void display(BTNode *b);
int BTNodeHeight(BTNode *b);

void createBTNode(BTNode *&b,char *str)
{
	BTNode *St[MaxSize],*p;
	int top=-1,k,j=0;
	char ch;
	b=NULL;
	ch=str[j];
	while(ch!='\0')
	{
		switch (ch)
		{
		case '(':
			{
				top++;
				St[top]=p;
				k=1;
				break;
			}
		case ')':
			{
				top--;
				break;
			}
		case ',':
			{
				k=2;
				break;
			}
		default:
			{
				p=(BTNode *)malloc(sizeof(BTNode ));
				p->data=ch;
				p->lchild=p->rchild=NULL;
				if(b==NULL)
				{
					b=p;
				}
				else
				{
					switch (k)
					{
					case 1:
						{
							St[top]->lchild=p;
							break;
						}
					case 2:
						{
							St[top]->rchild=p;
							break;
						}
					}
				}
			}
		}
		j++;
		ch=str[j];
	}
}

void display(BTNode *b)
{
	if(b!=NULL)
	{
		printf("%c",b->data);
		if(b->lchild!=NULL||b->rchild!=NULL)
		{
			printf("(");
			display(b->lchild);
			if(b->rchild!=NULL)
			{
				printf(",");
			}
			display(b->rchild);
			printf(")");
		}
	}
}
int BTNodeHeight(BTNode *b)
{
	int lchild,rchild;
	if(b==NULL)
	{
		return 0;
	}
	else{
		lchild=BTNodeHeight(b->lchild);
		rchild=BTNodeHeight(b->rchild);
		return (lchild>rchild)?(lchild+1):(rchild+1);
	}
}

int main()
{
	BTNode *p=NULL;
	//char[] a={'A','(','B','(','D','(',',','G',')',')',',','C','(','E',','}
	char *a="A(B(D(,G)),C(E,F))";
	createBTNode(p,a);
	display(p);
	int height = BTNodeHeight(p);
	return 0;
}