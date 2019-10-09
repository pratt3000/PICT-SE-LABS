//============================================================================
// Name        : a_10_deque.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class dq{
	int a[100];
	int start,end;
public:
	dq(){
		start = 50;
		end = 50;
	}
	void frontadd(){
		cout<<"ELEMENT:";
		cin>>a[start];
		cout<<endl;
		start--;
	}
	void frontdel(){
		cout<<"~DELETED";
			start++;
		}
	void backadd(){
			cout<<"ELEMENT:";
			end++;
			cin>>a[end];
			cout<<endl;

		}
	void backdel(){
		cout<<"~DELETED";
			end--;
		}
	void display(){
		for(int i = start+1;i<=end; i++){
			cout<<"\nelement"<<i-start<<" : "<<a[i];
		}
		cout<<endl;
	}
};
int main() {
	dq ob;
	cout<<"\nDOUBLE ENDED QUEUE";
	int i =1;
	cout<<"\nOPTIONS"
			<<"\n1:FRONT ADD"
			<<"\n2:FRONT DELETE"
			<<"\n3:BACK ADD"
			<<"\n4:BACK DELETE"
	  	    <<"\n5:DISPLAY"<<endl;
	while(i){
		cout<<"CHOICE : ";
		int ch;
		cin>>ch;
		switch(ch){
		case 1:ob.frontadd();break;
		case 2:ob.frontdel();break;
		case 3:ob.backadd();break;
		case 4:ob.backdel();break;
		case 5:ob.display();break;
		default:break;
		}
		cout<<"CONTINUE(1/0) : ";
		cin>>i;
	}
	return 0;
}
