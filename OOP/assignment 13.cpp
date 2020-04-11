//============================================================================
// Name        : assignment.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

string nameSearch;

class studentRecord{
	string birth;
	int number;
public:
	string name;
	studentRecord();
	void readData();
	void displayData();

};
studentRecord :: studentRecord(){
	name = " ";
	birth =" ";
	number = 0;
}
void studentRecord :: readData(){
	cout<<"NAME : ";
	cin>>name;
	cout<<"BIRTHDATE : ";
	cin>>birth;
	cout<<"PHONE NUMBER : ";
	cin>>number;
}
void studentRecord :: displayData(){
	cout<<"NAME : ";
	cout<<name<<endl;
	cout<<"BIRTHDATE : ";
	cout<<birth<<endl;
	cout<<"PHONE NUMBER : ";
	cout<<number<<endl;
	cout<<"-------------\n";
}
bool comp(const studentRecord &p, const studentRecord &q){
	return p.name<q.name;
}

int main() {
	string st[100];
	studentRecord ob[100];
	int count;
	cout<<"ENTER NUMBER OF STUDENTS : ";
	cin>>count;
	for(int i=0; i<count; i++)
		ob[i].readData();

	cout<<"\n-------MENU------"
		<<"\n1:SORT"
		<<"\n2:SEARCH"
		<<"\n3/:EXIT"<<endl;
	int i=1;
	while(i){
		cout<<"----------\nCHOICE = ";
		int choice;
		cin>>choice;
		switch(choice){
		case 1: sort(ob, ob + count, comp );
				for(int i=0;i<count;i++)
				ob[i].displayData();
				break;
		case 2:
		        sort(ob, ob + count, comp );
		        for(int i=0;i<count; i++)
		        	st[i] = ob[i].name;
				cout<<"\n SEARCH NAME: ";
				cin>>nameSearch;
				if(binary_search(ob, ob + count, nameSearch)){\
					cout<<"found";
					break;
				}
				cout<<"not found";
				break;
		default:break;
		}
		cout<<"CONTINUE?(1/0)";
		cin>>i;
	}
	cout<<"\n~terminated";
	return 0;
}
