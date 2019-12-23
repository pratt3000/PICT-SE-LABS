#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;
	node *prev;
}*head;

void create()
	{
		int n;
		head=NULL;
		node *p;
		p=head;
		cout<<"Enter no. of nodes"<<endl;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			node *q;
			cout<<"Enter the data"<<endl;
			q=new node;
			cin>>q->data;
			q->next=NULL;
			q->prev=NULL;
			if(p==NULL)
			{
				p=q;
				head=q;
			}
			else
			{
			q->prev=p;
			p->next=q;
			p=p->next;
			}
		}
	}
void deletep(node *t)
{
int d;
cout<<"Enter the position you want to delete"<<endl;
cin>>d;
for(int i=0;i<d;i++)
	{
	t=t->next;
	}
t=t->next->next;
t->next->next->prev=t;
}
void display(node *t)
{
	while(t!=NULL)
	{
		cout<<t->data<<endl;
		t=t->next;
	}
}
void deletef(node *t)
{
	cout<<"f";
t=t->next;
}
void deleteb(node *t)
{
	node *q;
	q=t->next;
	q->prev=t;
	while(q->next!=NULL)
	{
		q=q->next;
		t=t->next;
	}
	t->next=NULL;
}
int main()
{
	create();
	display(head);
	deletef(head);
	 deleteb(head);
	//deletep(head);
	display(head);
}
