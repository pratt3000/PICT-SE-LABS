//============================================================================
// Name        : uyt.cpp
// Author      : tera baap
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class binary
{
	int no;
	binary *next;
	binary *prev;
public:
    friend class list;
    friend void fun(binary * );

};
class list
{
	binary *head;
	binary *tail;
public:
	void compute_no(int & );
	void input(int &);
	void display();
	void comp_one();
	void comp_two();
	friend void fun(binary * );
	list()
	{
		head=NULL;
		tail=NULL;
	}

};


void list::compute_no(int &no)
{


	int binaryNum[32];
	int i = 0;
	    while (no > 0)
	    {
	        binaryNum[i] = no % 2;
	        no = no / 2;
	        i++;
	    }

	      for (int j = i - 1; j >= 0; j--)
	        cout << binaryNum[j];
	}


void list::input(int &x)
{
	binary *ptr;
	ptr=new binary;
	ptr->no=x;
	if(!head)
	{
	head=ptr;
	tail=ptr;
	}
	else
	{
		binary *temp=head;
				while(temp->next!=NULL)
					{
					temp=temp->next;
					}

				    temp->next=ptr;
				    ptr->prev=temp;
				    ptr->next=NULL;
				    tail=ptr;
	}
	/*binary *t=head;
		int cnt=0;
	    do
	  {
	      cout<<"\n"<<t->no;
		  t=t->next;
		  cnt++;
	  }while(t!=NULL);

	   cout<<"\nTotal members :"<<cnt--;*/
}

void list::comp_one()
{
	binary *temp=head;
	while(temp!=NULL)
	{
		temp->no=!temp->no;
			temp=temp->next;

	}

}

void fun(binary *p)
   {
	   while(p->prev!=NULL)
  {
	   if(p->no==0)
	   {
		   p->no=1;
	   }
	   else
	   {
		   p->no=0;
		   fun(p->prev);
	   }

   }
 }

void list::comp_two()
{
   binary *p=tail;
   fun(p);

}

void list::display()
{
	binary *t=head;
			int cnt=0;
			cout<<"\n";
		    do
		  {
		      cout<<t->no;
			  t=t->next;
			  cnt++;
		  }while(t!=NULL);

		   cout<<"\nTotal members :"<<cnt--;

		   binary *p=tail;
		 	cout<<"\n";
		   		    do
		   		  {
		   		      cout<<p->no;
		   			  p=p->prev;

		   		  }while(p!=NULL);


}

int main()
{   int no,option;
    char choice;
    list a;
     cout<<"Enter the decimal no";
     cin>>no;

 	int binaryNum[32];
 	int i = 0;
 	    while (no > 0)
 	    {
 	        binaryNum[i] = no % 2;
 	        no = no / 2;
 	        i++;
 	    }
 	   for (int j = i - 1; j >= 0; j--)
 	   	        {
 	   	    	  cout << binaryNum[j];
 	   	        }
 	      for (int j = i - 1; j >= 0; j--)
 	        {
 	    	  a.input(binaryNum[j]);
 	        }
 	     cout<<"dGFJKf";
 	    // a.comp_one();
 	     a.display();
 	     cout<<"dhf";
 	     a.comp_two();
 	     cout<<"yk";
 	     a.display();
 	    /* do
 	   {
 	   cout<<"Enter your choice";
      cin>>option;

 		 switch(choice)
 		 {
 		 case 1: a.comp_one();
 		           a.display();
 		           break;

 		 default :cout<<"Wrong choice";

 		 }
 		 cout<<"Enter choice(y/n)";
 		         cin>>choice;
 	   }while(choice=='y');


*/

	return 0;
}
