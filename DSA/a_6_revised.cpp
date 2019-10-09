
#include<bits/stdc++.h>
using namespace std;



class Node
{
	string name;
	Node *next;
public:
	Node();
	Node(string);
	void display();

	friend class Cream;
};
Node::Node()
{
	name="";
	next=NULL;
}
Node::Node(string a)
{
   name=a; next=NULL;
}
void Node::display()
{
	cout<<name<<" "<<endl;
}

class Cream
{
	Node *start;
	Node *start2;
	Node *start3;
	Node *start4,*start5,*start6;
public:
	void read(int p,int q);
	void displayu();
	void displayov();
	void displayob();
	void displayvb();
	void displayvub();
	void displayn(int);
};

void Cream::read(int p,int q)
{
	    string name;
	    string fav;
		Node *t2,*t3;
		int i=1;
		if(p==0)
		{
			cout<<"Vanilla List Empty!"<<endl;
		}
		else if(q==0)
		{
			cout<<"Butterscotch List Empty!"<<endl;
		}
		else
		{
		cout<<"Enter the name of students who like VANILLA"<<endl;
		while(i<=p)
		{
			cin>>name;
			if(i==1)
			{
				 start2=new Node(name);
				 t2=start2;
				 i++;
			}
			else
			{
			Node *present=new Node(name);
			t2->next=present;
			t2=present;
			i++;
			}
		}
		i=1;
		cout<<"Enter the name of students who like BUTTERSCOTCH"<<endl;
		while(i<=q)
		{
			cin>>name;
			if(i==1)
			{
				start3=new Node(name);
			    t3=start3;
			    i++;
			}
			else
			{
			    Node *present=new Node(name);
				t3->next=present;
				t3=present;
				i++;
			}
		}
		}
}


void Cream::displayu()
{
	if(start2==NULL || start3==NULL)
		{
			cout<<"EMPTY LIST!"<<endl;
		}
	else
	{
     Node *t;
	cout<<"Vanilla List :- "<<endl;
	    t=start2;
		while(t!=NULL)
		{
			t->display();
			t=t->next;
		}

		cout<<"Butterscotch List :- "<<endl;
		t=start3;
				while(t!=NULL)
				{
					t->display();
					t=t->next;
				}
	}
}

void Cream::displayov()
{
	int i=0;
	Node *t3;
	cout<<"ONLY Vanilla List :- "<<endl;
		    Node *t=start2;

			while(t!=NULL)
			{
				i=0;
				Node *t2=start3;
				while(t2!=NULL)
				{
					if(t->name==t2->name)
					{
						i=1;
						break;
					}
					t2=t2->next;
				}
				if(i==1)
				{
					t=t->next;
					continue;
				}
				else if(i==0)
				{
					start=new Node(t->name);
					t3=start;
					i++;
				}
				else
				{
					Node *present=new Node(t->name);
					t3->next=present;
					t3=present;
					i++;
				}
				t->display();
				t=t->next;
			}
}

void Cream::displayob()
{
	int i=0;
	Node *t4;
		cout<<"ONLY Butterscotch List :- "<<endl;
			    Node *t=start3;

				while(t!=NULL)
				{
					i=0;
					Node *t2=start2;
					while(t2!=NULL)
					{
						if(t->name==t2->name)
						{
							i=1;
							break;
						}
						t2=t2->next;
					}
					if(i==1)
					{
						t=t->next;
						continue;
					}
					             else if(i==0)
									{
										start4=new Node(t->name);
										t4=start4;
										i++;
									}
									else
									{
										Node *present=new Node(t->name);
										t4->next=present;
										t4=present;
										i++;
									}
					t->display();
					t=t->next;
				}
}

void Cream::displayvb()
{
			cout<<"Vanilla INTERSECTION Butterscotch List :- "<<endl;
				    Node *t=start2;
                  int i=0;
                  Node *t5;
					while(t!=NULL)
					{
						Node *t2=start3;
						while(t2!=NULL)
						{
							if(t->name==t2->name)
							{
								if(i==0)
								{
									start5=new Node(t->name);
									t5=start5;
									i++;
								}
								else
								{
									Node *present=new Node(t->name);
									t5->next=present;
									t5=present;
								    i++;
								}
								t->display();
								break;
							}
							t2=t2->next;
						}
						t=t->next;
					}
}

void Cream::displayvub()
{
	Node *t1=start2;
	Node *t2=start3;
	//Node *t3=start5;
	Node *t6;
	start6 =new Node(t1->name);
	t6=start6;
	cout<<"Vanilla UNION Butterscotch List:-"<<endl;
	t1->display();
	t1=t1->next;
	while(t1!=NULL)
	{
		Node *present=new Node(t1->name);
		t6->next=present;
		t6=present;
		t1->display();
		t1=t1->next;
	}
	int i=0;
	            while(t2!=NULL)
					{
						i=0;
						t1=start2;
						while(t1!=NULL)
						{
							if(t1->name==t2->name)
							{
								i=1;
								break;
							}
							t1=t1->next;
						}
						if(i==1)
						{
							t2=t2->next;
							continue;
						}

							Node *present=new Node(t2->name);
								t6->next=present;
								t6=present;
								i++;

						t2->display();
						t2=t2->next;
					}
	t6->next=NULL;

}

void Cream::displayn(int t)
{
     Node *t6=start6;
     int c=0;
     while(t6!=NULL)
     {
    	 c++;
    	 t6=t6->next;
     }
     cout<<"Number of students who don't like VANILLA as well as BUTTERSCOTCH - "<<(t-c)<<endl;
}


int main()
{

	int n,v,b;
	Cream o1;
	cout<<"Enter the number of students"<<endl;
	cin>>n;
	cout<<"Enter the number of students who like VANILLA";
	cin>>v;
	cout<<"Enter the number of students who like BUTTERSCOTCH";
	cin>>b;
	o1.read(v,b);
	o1.displayu();
		o1.displayov();
		o1.displayob();
		o1.displayvb();
		o1.displayvub();
		o1.displayn(n);
}

