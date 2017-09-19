#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct link
{
	int data;
	struct link *next;
};
struct link *input(struct link *head)
{
	struct link *pr = head,*p = NULL;
	int data;
	p = (struct link *)malloc(sizeof(struct link));
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		while (pr->next != NULL)
		{
			pr = pr ->next;
		}
		pr->next = p;
	}
	cout<<"input the data \n";
	cin>>data;
	p->data = data;
	p->next = NULL;
	return head;
}

void show(struct link *head)
{
	struct link *pr = head;
	int i = 1;
	while (pr != NULL)
	{
		cout<<i<<" "<<pr->data<<endl;
		pr = pr->next;
		i++;
	}
}
void free(struct link *head)
{
	struct link *pr = head,*p = NULL;
	while(pr != NULL)
	{
		p = pr;
		pr = pr->next;
		delete(p);
	}
}

struct link *del(struct link *head,int data)
{
	struct link *p = head, *pr = NULL;
	if (head == NULL)
	{
		cout<<"link is no \n";
		return (head);
	}
	while (p->data != data && p->next != NULL)
	{
		pr = p;
		p = p->next;
	}
	if (data == p->data)
	{
		if (p == head)
		{
			head = p->next;
		}
		else
		{
			pr->next = p->next;
		}
		delete(p);
	}
	else
	{
		cout<<" 没有找到 \n";
	}
	return head;
	

}

int main()
{
	char c;
	struct link *head = NULL;
	cout<<"input y or n \n";
	cin>>c;
	while (c == 'y')
	{
		head = input(head);
		show(head);
		cout<<"input y or n\n";
		cin>>c;
	}
	cout<<"链表已建立 \n";
	cout<<"do you want to del a data? \n y or n \n";
	cin>>c;
	if (c == 'y')
	{
		int m;
		cout<<"input the data \n";
		cin>>m;
		head = del(head,m);
	}
	show(head);
	free(head);
	return 0;
}