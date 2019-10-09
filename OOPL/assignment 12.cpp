//============================================================================
// Name        : dequeue.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
void show(deque <int> dq){
	cout<<"\n ----- DEQUE -----\n";
		while(!dq.empty()){
			cout<<dq.front()<<endl;
			dq.pop_front();
		}
}
int main() {
	deque <int> dq;
		cout<<"STACK";
		cout<<"\nENTER NO. OF INPUTS : ";
		int inputs, thing;
		cin>>inputs;
		while(inputs--){
			cout<<"ENTERY : ";
			cin>>thing;
			dq.push_front(thing);
		}
		cout<<"\n-------MENU------"
			<<"\n1:INSERT FROM FRONT"
			<<"\n2:INSERT FROM BACK"
			<<"\n3:REMOVE FROM FRONT"
			<<"\n4:REMOVE FROM BACK"
			<<"\n5:DISPLAY"
			<<"\n6:SIZE OF DEQUE"
			<<"\n7:DISPLAY FRONT"
			<<"\n8:DISPLAY BACK"
			<<"\n9/:EXIT"<<endl;

		int i=1;
		while(i){
			cout<<"----------\nCHOICE = ";
			int choice;
			cin>>choice;
			switch(choice){
			case 1: cout<<"ENTERY : ";
					cin>>thing;
					dq.push_front(thing);
					break;
			case 2: cout<<"ENTERY : ";
					cin>>thing;
					dq.push_back(thing);
					break;
			case 3: dq.pop_front();
					break;
			case 4: dq.pop_back();
					break;
			case 5: show(dq);
					break;
			case 6: cout<<"SIZE = "<<dq.size()<<endl;
					break;
			case 7: cout<<"FRONT = "<<dq.front()<<endl;
					break;
			case 8: cout<<"BACK = "<<dq.back()<<endl;
					break;
			default:break;
			}
			cout<<"CONTINUE?(1/0)";
			cin>>i;
		}
		cout<<"\n~terminated";
	return 0;
}
