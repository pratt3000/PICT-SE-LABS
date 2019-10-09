//============================================================================
// Name        : a_5_doubly_linked_list.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class node{
	bool bin; 									  // data
	node *next, *prev;							//pointers
public:
	node(){
		bin=0;
		next = NULL;
		prev = NULL;
	}
	node(int b){
		bin=b;
		next = NULL;
		prev = NULL;
	}
	friend class data;							 // to access
};

class data{
	node *start;
public:
	data(){ start = NULL; }
	void addp(bool b);			// front msb
	void adds(bool b);			// back lsb
	void onec();
	void twoc();
	void add(data &ob2);
	void display();
	void convert( int num);						//num to binary
	int total();
};

void data :: addp(bool b){
	node *temp = new node(b);
	if(start == NULL){
		cout<<"BIT ADDED(MSB)\n";
		temp -> next = NULL;
		temp -> prev = NULL;
		start  = temp;
	}
	else{
		cout<<"BIT ADDED(MSB)\n";
		temp -> next = start;
		start -> prev = temp;
		start = temp;
		start -> prev = NULL;
	}
}
void data :: adds(bool b){
	node *t = start;
	node *temp = new node(b);
	if(start == NULL){
		cout<<"BIT ADDED(LSB)\n";
	    temp -> next = NULL;
		temp -> prev = NULL;
		start  = temp;
	}
	else{
		cout<<"BIT ADDED(LSB)\n";
		while(t -> next  != NULL)
			t = t -> next;
		temp -> next = NULL;
		temp -> prev = t;
		t -> next = temp;
	}
}
void data :: display(){
	node *t = start;
	cout<<"\nBINARY NUMBER :\n";
	if(t == NULL)		cout<<"\nEMPTY LIST";
	else{
		while(t!=NULL){
			cout<<t -> bin;
			t = t -> next;
		}
	cout<<"\n";
	}
}
int data  :: total(){
	node *t = start;
	int count = 0;
	if(start == NULL){
			return 0;
		}
		else{
			while((t -> next) != NULL){
				t = t -> next;
				count++;
			}
			return (count + 1);
		}
}
void data :: onec(){
	node *t = start;
	int x;
	x = total();
	while(x--){
		if(t -> bin == 1)
			t -> bin = 0;
		else if(t -> bin == 0)
			t -> bin = 1;
		t = t -> next;
	}
	cout<<endl;
	cout<<"\nONE'S COMPLIMENT:";
	display();
}
void data :: twoc(){
	node *t = start;
	bool carry = 0;
	int count = total();
	count--;
	onec();
	while((t -> next) != NULL)
		t = t -> next;
	if(t -> bin == 1){
		t -> bin = 0;
		carry = 1;
	}
	else
		t -> bin = 1;
	t = t -> prev;
	while( carry ){
		if(t -> bin == 1){
			t -> bin = 0;
		}
		else{
			carry = 0;
			t -> bin = 1;
		}
		t = t -> prev;
	}
	cout<<"\nTWO'S COMPLIMENT:";
	display();
}
void data :: add(data &ob2){
	node *t, *t2;
	bool carry = 0;
	int count;
	int count1 = total();
	int count2 = ob2.total();
	int difference = abs(count1 - count2);
	if(count1 > count2){
		count = count1;
		while(difference--)				ob2.addp(0);
	}
	else{
		count = count2;
		while(difference--)				addp(0);
	}
	t = start;
	t2 = ob2.start;
	while((t -> next) != NULL){
		t = t -> next;
		t2 = t2 -> next;
	}
	while(count--){
		if(carry == 0){
			if(t -> bin == 1 && t2 ->bin == 1 ){
				carry = 1;
				t -> bin = 0;
			}
			else if((t -> bin == 0 && t2 -> bin ==1) || (t -> bin == 1 && t2 -> bin == 0) ){
				carry = 0;
				t -> bin = 1;
			}
			else if(t -> bin == 0 && t2 -> bin == 0 ){
				carry = 0;
				t -> bin = 0;
			}
		}
		else if(carry == 1){
			if(t -> bin == 1 && t2 -> bin == 1 ){
				carry = 1;
				t -> bin = 1;
			}
			else if((t -> bin == 0 && t2 -> bin ==1) || (t -> bin == 1 && t2 -> bin == 0) ){
				carry = 1;
				t -> bin = 0;
			}
			else if(t -> bin == 0 && t2 -> bin == 0 ){
				carry = 0;
				t -> bin = 1;
			}
		}
		t = t -> prev;
		t2 = t2 -> prev;
	}
	if(carry == 1)			addp(1);
	cout<<"\nADDITION: ";
	display();
}
void data :: convert(int num){
	if(num!= 1){
		adds(num % 2);
		num /= 2;
		while(num != 1){
			if(num % 2 == 0)
				addp( 0 );
			else
				addp( 1 );
			num /= 2;
		}
	}
	addp(1);
	display();
}

int main() {
	data *ob, ob1, ob2;
	int count = 0;
	int l=1;
	int e=1;
	int x;
	bool b;
	int num1,num2;
	cout<<"ENTER LIST NUMBER (1/-1)";  		// switch list
	cin>>l;
c:	if(count < 2){
		if(l == 1){
			cout<<"\nLIST 1";
			ob = &ob1;
			cout<<"\nINPUT FIRST NUMBER : ";
			cin>>num1;								//cout<<"check";
			ob -> convert(num1);
		}
		if(l == -1){
			cout<<"\nLIST 2";
			ob = &ob2;
			cout<<"\nINPUT SECOND NUMBER : ";
			cin>>num2;
			ob -> convert(num2);
		}
	}
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~ LIST ~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<"\n1  : ADD MSB";
	cout<<"\n2  : ADD LSB";
	cout<<"\n3  : TOTAL NODES";
	cout<<"\n4  : DISPLAY";
	cout<<"\n5  : 1's COMPLIMENT";
	cout<<"\n6  : 2's COMPLIMENT";
	cout<<"\n7  : ADDITION";
	cout<<"\n8  : SWITCH BINARY NUMBER\n";
	while(e){
		cout<<"CHOICE : ";
		cin>>x;
		switch (x){
			case 1 : cout<<"----------------------\n";
					 cout<<"ADD MSB(BINARY NO.): ";			cin>>b;
					 if(b == 1 || b == 0)
						 ob -> addp(b);
					 break;
			case 2 : cout<<"----------------------\n";
			 	 	 cout<<"ADD LSB(BINARY NO.): ";			cin>>b;
			 	 	 if(b == 0 || b == 1)
			 	 		 ob -> adds(b);
					 break;
			case 3 : int r;
			         r = ob -> total();
					 if(r == 0) cout<<"\nNUMBER DNE";
					 else 	 cout<<"NO. OF BITS = "<<r<<endl;
					 break;
			case 4 : ob->display();
					 break;
			case 5 : ob->onec();
					break;
			case 6 : ob->twoc();
					break;
			case 7 : ob1.add(ob2);
					break;
			case 8 : count++;
					 l *= -1;
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
