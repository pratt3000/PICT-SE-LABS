//============================================================================
// Name        : a_4_linked_list.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of Second, third and final year of department can be granted membership on request. Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club. Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and Name. Write functions to
//				 Add and delete the members as well as president or even secretary.
//				 Compute total number of members of club
//				 Display members
//				 Display list in reverse order using recursion
//				 Two linked lists exists for two divisions. Concatenate two lists Sort the singly linked list.
//				 OR
//				 Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of Second, third and final year of department can be granted membership on request. Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club. Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and Name. Write functions to
//			 	 Add and delete the members as well as president or even secretary.
//				 Compute total number of members of club
//				 Display members
//				 Display list in reverse order using recursion
//				 Two linked lists exists for two divisions. Concatenate two lists
//				 Merge two sorted singly linked lists.
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class node{
	int roll;
	string name,div;
	node *next;
public:

	node(){
		roll = 0;
		name = " ";
		div = " ";
		next = NULL;
	}
	node(int r , string d , string n){
		//read(r,d,n);
		roll = r;
		name = n;
		div = d;
		next = NULL;
	}
	friend class data;
};
class data{
	node *start;
public:
	data(){ start = NULL; }
	void addp(int r,string d, string n);
	void adds(int r,string d, string n);
	void addm(int r,string d, string n);
	void deletep(int r,string d,string n);
	void deletes(int r,string d,string n);
	void deletem(int r,string d,string n);
	int total();
	void display();
	void revdisplay();
	data concat(data &ob1);
	void sort();
	void rever(node *t);
};

void data :: addp(int r,string d, string n){
	node *temp = new node(r,d,n);
	if(start == NULL){
		cout<<"FIRST NODE CREATED (PRESIDENT)\n";
		temp->next = NULL;
		start  = temp;
	}
	else{
		temp->next = start;
		start = temp;
	}
}
void data :: adds(int r,string d, string n){
	node *t = start;
	node *temp = new node(r,d,n);
	if(start == NULL)
		cout<<"NO PRESIDENT, NO SECRETARY\n";
	else{
		while(t ->next  != NULL)
			t = t->next;
		temp->next = NULL;
		t->next = temp;
	}
}
void data :: addm(int r,string d, string n){
		node *temp = new node(r,d,n);
		if(start == NULL)
			cout<<"NO PRESIDENT, NO SECRETARY\n";
		else{
			temp->next = start->next;
			start->next = temp;
		}
}
void data :: deletep(int r,string d,string n){
	if(start == NULL){
		cout<<"NOTHING TO DELETE";
	}
	else{
		start = start->next;
	}
}
void data :: deletes(int r,string d,string n){
	node *t = start;
	if(start == NULL){
			cout<<"\nNOTHING TO DELETE";
		}
		else{
			while((t ->next)->next != NULL)
				t = t->next;
			t ->next = NULL;
		}
}
void data :: deletem(int r,string d,string n){
	if(start == NULL){
			cout<<"NOTHING TO DELETE";
		}
	else{
			start-> next = (start -> next) ->next;
		}
}
int data  :: total(){
	node *t = start;
	int count = 0;
	if(start == NULL){
			return 0;
		}
		else{
			while((t ->next) != NULL){
				t = t->next;
				count++;
			}
			return count;
		}
}
void data :: display(){
	node *t = start;
	int i=1;
	cout<<"  NAME\t"<<"ROLL NO.  "<<"DIVISION \t";
	if(t == NULL)		cout<<"\nEMPTY LIST";
	else{
		while(t!=NULL){
			cout<<"\n"<<i;
			cout<<": "<<t->name;
			cout<<" \t"<<t->roll;
			cout<<"  \t  "<<t->div;
			t = t->next;
			i++;
		}
	cout<<"\n";
	}
}
void data :: revdisplay(){
	if(start == NULL){
			cout<<"\nEMPTY LIST";
		}
	else{
			rever(start);
		}
}
data data :: concat(data &ob1){
	node *t;
	if(start == NULL)			{cout<<"\nLIST 1 IS EMPTY";	return ob1;}
	else if(ob1.start == NULL)	{cout<<"\nLIST 2 IS EMPTY";	return ob1;}
	t = ob1.start;
	while(t->next != NULL)
		t = t->next;
	t->next = start;
	return ob1;

}
void data :: sort(){
	string name,div;
	int rn;
	for( node *i = start; i!= NULL; i = i->next){
		for( node *j = i->next ; j!= NULL; j = j->next){
			cout<<i->roll<<" "<<j->roll;
			if((i->roll) > (j->roll)){
				name = (i->name);
				(i->name) = (j->name);
				(j->name) = name;

				rn = (i->roll);
				(i->roll) = (j->roll);
				(j->roll) = rn;

				div = (i->div);
				(i->div) = (j->div);
				(j->div) = div;

			}
		}
	}
}

void data :: rever(node *t){
	if(t-> next == NULL)
		return;
	else{
		rever(t->next);
		cout<<t->name;
		cout<<" \t"<<t->roll;
		cout<<" \t"<<t->div;
	}
}
int main() {
	data *ob,ob1,ob2;
	int l;
	cout<<"ENTER LIST NUMBER (1/-1)";			cin>>l;
c:	if(l==1)		{cout<<"\nLIST 1";ob = &ob1;}
	if(l==-1)		{cout<<"\nLIST 2";ob = &ob2;}
	int r;
	int x;
	string d,n;
	int e=1;
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~ LIST ~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<"\n1  : ADD PRESIDENT";
	cout<<"\n2  : ADD SECRETARY";
	cout<<"\n3  : ADD MEMBER";
	cout<<"\n4  : DELETE PRESIDENT";
	cout<<"\n5  : DELETE SECRETARY";
	cout<<"\n6  : DELETE MEMBER";
	cout<<"\n7  : TOTAL";
	cout<<"\n8  : DISPLAY";
	cout<<"\n9  : REVDISPLAY";
	cout<<"\n10 : CONCATINATE";
	cout<<"\n11 : SORT";
	cout<<"\n12 : SWITCH LIST \n";
	while(e){
	cout<<"CHOICE : ";
	cin>>x;
	switch (x){
		case 1 : cout<<"----------------------\n";
				 cout<<"NAME : ";			cin>>n;
			 	 cout<<"ROLL NO. : ";		cin>>r;
				 cout<<"DIVISION : ";		cin>>d;
			     ob->addp(r,d,n);
				 break;
		case 2 : cout<<"----------------------\n";
		 	 	 cout<<"NAME : ";			cin>>n;
		 	 	 cout<<"ROLL NO. : ";		cin>>r;
		 	 	 cout<<"DIVISION : ";		cin>>d;
				 ob->adds(r,d,n);
				 break;
		case 3 : cout<<"----------------------\n";
				 cout<<"NAME : ";			cin>>n;
		         cout<<"ROLL NO. : ";		cin>>r;
		         cout<<"DIVISION : ";		cin>>d;
			     ob->addm(r,d,n);
				 break;
		case 4 : ob->deletep(r,d,n);
				 break;
		case 5 : ob->deletes(r,d,n);
				 break;
		case 6 : ob->deletem(r,d,n);
				 break;
		case 7 : int r;
		         r = ob->total();
				 if(r==0) cout<<"\nEMPTY LIST";
				 else 	 cout<<"\nNO. OF ELEMENTS = "<<r;
				 break;
		case 8 : ob->display();
				 break;
		case 9 : ob->revdisplay();
				 break;
		case 10 :ob2.concat(ob1);
				 break;
		case 11 : ob->sort();
				 break;
		case 12 : l *= -1;
				  goto c;
				  break;
		default:break;
		}
		cout<<"----------------------\nCONTINUE?(1/0) : ";
		cin>>e;
	}
	cout<<"~terminated";
	return 0;
}
