//============================================================================
// Name        : STL_stackqueue.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
void display(stack <int> st){
	cout<<"\n ----- STACK -----";
	while(!st.empty()){
		cout<<st.top()<<endl;
		st.pop();
	}
}

void show(queue <int> gq)
{
    queue <int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

int main() {

	cout<<"STACK or QUEUE?(1/2)";
	int choice;
	stack <int> st;
	queue <int> qu;
	cin>>choice;
	if(choice==1){
		cout<<"STACK";
		cout<<"\nENTER NO. OF INPUTS : ";
		int inputs, thing;
		cin>>inputs;
		while(inputs--){
			cout<<"ENTERY : ";
			cin>>thing;
			st.push(thing);
		}
		cout<<"\n-------MENU------"
			<<"\n1:PUSH"
			<<"\n2:POP"
			<<"\n3:SIZE"
			<<"\n4:TOP"
			<<"\n5:DISPLAY"
			<<"\n6/:EXIT"<<endl;

		int i=1;
		while(i){
			cout<<"----------\nCHOICE = ";
			int choice;
			cin>>choice;
			switch(choice){
			case 1: cout<<"ENTERY : ";
					cin>>thing;
					st.push(thing);
					break;
			case 2: st.pop();
					cout<<"\n~popped"<<endl;
					break;
			case 3: cout<<"SIZE : "<<st.size()<<endl;
					break;
			case 4: cout<<"TOP : "<<st.top()<<endl;
					break;
			case 5: display(st);
					break;
			default:break;
			}
			cout<<"CONTINUE?(1/0)";
			cin>>i;
		}
		cout<<"\n~terminated";
	}
	else{
		cout<<"\nQUEUE";
		cout<<"\nENTER NO. OF INPUTS : ";
		int inputs, thing;
		cin>>inputs;
		while(inputs--){
			cout<<"ENTERY : ";
			cin>>thing;
			qu.push(thing);
		}
		cout<<"\n-------MENU------"
					<<"\n1:PUSH"
					<<"\n2:FRONT"
					<<"\n3:BACK"
					<<"\n4:SIZE"
					<<"\n5:DISPLAY"
					<<"\n6/:EXIT"<<endl;

				int i=1;
				while(i){
					cout<<"----------\nCHOICE = ";
					int choice;
					cin>>choice;
					switch(choice){
					case 1: cout<<"ENTERY : ";
							cin>>thing;
							qu.push(thing);
							break;
					case 2: cout<<"FRONT : "<<qu.front()<<endl;
							break;
					case 3: cout<<"BACK : "<<qu.back()<<endl;
							break;
					case 4: cout<<"SIZE : "<<qu.size()<<endl;
							break;
					case 5: show(qu);
							break;
					default:break;
					}
					cout<<"CONTINUE?(1/0)";
					cin>>i;
				}
				cout<<"\n~terminated";

	}
	return 0;
}
