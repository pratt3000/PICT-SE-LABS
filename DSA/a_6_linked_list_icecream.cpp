//============================================================================
// Name        : a_6_linked_list_icecream.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class node{
	bool v,b;
	string name;
	node *next;
public:

	node(){
		b = 0;
		name = " ";
		v = 0;
		next = NULL;
	}
	node(bool v , bool b , string n){
		//read(r,d,n);
		this->v = v;
		name = n;
		this->b = b;
		next = NULL;
	}
	friend class data;
};

class data{
	node *start;
public:
	data(){ start = NULL; }
	void addstudent(bool v,bool b, string n);
	int total();
	void displayall();
	void displayvanilla();
	void displaybutterscotch();
	void displaynone();
};
void data :: addstudent(bool v,bool b, string n){
	node *temp = new node(v,b,n);
	if(start == NULL){
		cout<<"FIRST NODE CREATED \n";
		temp->next = NULL;
		start  = temp;
	}
	else{
		temp->next = start;
		start = temp;
	}
	return;
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
void data :: displayall(){
	node *t = start;
	int i=1;
	cout<<"  NAME\t"<<"VANILLA  "<<"BUTTERSCOTCH \t";
	if(t == NULL)		cout<<"\nEMPTY LIST";
	else{
		while(t!=NULL){
			cout<<"\n"<<i;
			cout<<": "<<t->name;
			cout<<" \t"<<t->v;
			cout<<"  \t  "<<t->b;
			t = t->next;
			i++;
		}
	cout<<"\n";
	}
}
void data :: displayvanilla(){
	node *t = start;
		int i=1;
		cout<<"  NAME\t"<<"VANILLA  "<<"BUTTERSCOTCH \t";
		if(t == NULL)		cout<<"\nEMPTY LIST";
		else{
			while(t!=NULL){
				if(t->v == 1){
					cout<<"\n"<<i;
					cout<<": "<<t->name;
					cout<<" \t"<<t->v;
					cout<<"  \t  "<<t->b;
				}
				t = t->next;
				i++;
			}
		cout<<"\n";
		}
}

void data :: displaybutterscotch(){
	node *t = start;
			int i=1;
			cout<<"  NAME\t"<<"VANILLA  "<<"BUTTERSCOTCH \t";
			if(t == NULL)		cout<<"\nEMPTY LIST";
			else{
				while(t!=NULL){
					if(t->b == 1){
						cout<<"\n"<<i;
						cout<<": "<<t->name;
						cout<<" \t"<<t->v;
						cout<<"  \t  "<<t->b;
					}
					t = t->next;
					i++;
				}
			cout<<"\n";
			}
}

void data:: displaynone(){
	node *t = start;
				int i=1;
				cout<<"  NAME\t"<<"VANILLA  "<<"BUTTERSCOTCH \t";
				if(t == NULL)		cout<<"\nEMPTY LIST";
				else{
					while(t!=NULL){
						if(t->b == 0 && t->v == 0){
							cout<<"\n"<<i;
							cout<<": "<<t->name;
							cout<<" \t"<<t->v;
							cout<<"  \t  "<<t->b;
						}
						t = t->next;
						i++;
					}
				cout<<"\n";
				}
}
int main() {
    data *ob;
    string n;
    bool v,b;



    int e=1,x;
    	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~ LIST ~~~~~~~~~~~~~~~~~~~~~~~~";
    	cout<<"\n1  : ADD STUDENT";
    	cout<<"\n2  : TOTAL STUDENTS";
    	cout<<"\n3  : DISPLAY ALL STUDENTS";
    	cout<<"\n4  : DISPLAY STUDENTS WHO LIKE ONLY VANILLA";
    	cout<<"\n5  : DISPLAY STUDENTS WHO LIKE ONLY BUTTERSCOTCH";
    	cout<<"\n6  : DISPLAY STUDENTS WHO LIKE NEITHER";
    	while(e){
    	cout<<"\nCHOICE : ";
    	cin>>x;
    	switch (x){
    		case 1 :cout<<"\nNAME : "; cin>>n;
    			cout<<"\nVANILLA?";	cin>>v;
    			cout<<"\nBUTTERSCOTCH?";	cin>>b;
    				 ob->addstudent( v, b, n);
    				 cout<<"f";
    				 break;
    		case 2 : cout<<ob->total();
    				 break;
    		case 3 : ob->displayall();
    				 break;
    		case 4 : ob-> displayvanilla();
    		    	 break;
    		case 5 : ob->displaybutterscotch();
    		    	 break;
    		case 6 : ob->displaynone();
    		    	 break;
    		default:break;
    		}
    		cout<<"----------------------\nCONTINUE?(1/0) : ";
    		cin>>e;
    	}
    	cout<<"~terminated";
	return 0;
}
