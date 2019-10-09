//============================================================================
// Name        : a_9_queue.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
int n=0;
class Task{
	int priority;
	string name;
public:
	friend class Queue;
};

class Queue{
	Task ob[10],ob2;
public:
	void input(){
			n++;
			int position;
			cout<<"priority : ";
			cin>>ob2.priority;
			cout<<"name : ";
			cin>>ob2.name;
			position = compare(ob2.priority);
			place(position);
	}
	int compare(int x){
		int i;
		for(i=1;i<n;i++){
			if(x < ob[i].priority)
				return i;
		}
		return i;
	}
	void place(int position){
		int i;
		for(i=n; i>position; i--){
			ob[i].name = ob[i-1].name;
			ob[i].priority = ob[i-1].priority;
		}
		ob[position].name     =    ob2.name;
		ob[position].priority =    ob2.priority;
	}
	void display(){
		cout<<"\nname\t\t"<<"priority";
		for(int i = 1 ; i<n+1; i++){
			cout<<"\n"<<ob[i].name<<"\t\t"<<ob[i].priority;
		}
	}
	void delete1(){
		for(int i = 1 ;i < n ; i++ ){
			ob[i].name = ob[i+1].name;
			ob[i].priority = ob[i+1].priority;
		}
		n--;
	}
};
int main() {
	Queue obj;
	int i=1;
	while(i){
		int choice;
		cout<<"\n1: INSERT";
		cout<<"\n2: DISPLAY";
		cout<<"\n3: DELETE";
		cout<<"\nCHOICE : ";
		cin>>choice;
		switch(choice){
		case 1:obj.input();
			break;
		case 2:obj.display();
			break;
		case 3:obj.delete1();
			   obj.display();
			   break;
		}
		cout<<"\ncontinue?";
		cin>>i;
	}

	return 0;
}
