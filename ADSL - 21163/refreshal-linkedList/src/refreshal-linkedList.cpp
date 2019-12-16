//============================================================================
// Name        : refreshal-linkedList.cpp
// Author      : Prathamesh Sonawane (21163)
// Description : Doubly linked list in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
//Node class : individual node initialization.
class Node{
	Node *next;
	Node *prev;
	int value;
public:
	Node(){
		next = NULL;
		prev = NULL;
		value = 99;
	}
	Node(int value){
		this->value = value;
		prev = NULL;
		next = NULL;
	}
	friend class List;
};
//List class
class List{
	Node *start;
	int val;
public:
	List();
	void insert();
	void remove();
	void display();
	void revdisplay();
	bool search();
};
//searching
bool List :: search(){
	bool found = 0;
	Node *temp = start;
	cout<<"\nTo search(integer) : ";
	int element;
	cin>>element;
	while(temp != NULL){
		if(temp->value == element){
			found = 1;
			break;
		}
		temp = temp->next;
	}
	return found;
}
//List class : constructor
List :: List(){
	start = NULL;
	val = 99;
}
//List class : add element from front
void List :: insert(){
	cout<<"next node value : ";
	cin>>val;
	if(start == NULL){
		start = new Node(val);
		start->next = NULL;
		start->prev = NULL;
	}
	else{
		Node *temp = new Node(val);
		temp->prev = NULL;
		temp->next = start;
		start->prev = temp;
		start = temp;
	}
}
//List class : remove from front
void List :: remove(){
	if(start == NULL){
		cout<<"\n~list empty";
	}
	else{
		start = start->next;
	}
}
//List class : display start to end
void List :: display(){
	Node *temp = start;
	int i=1;
	cout<<"\nList start";
	while(temp != NULL){
		cout<<"\n"<<i<<". "<<temp->value;
		i++;
		temp = temp->next;
	}
	cout<<"\nList end\n";
}
//List class : display end to start
void List :: revdisplay(){
	Node *temp = start;
	while(temp->next != NULL)
		temp = temp->next;
	int i=1;
	cout<<"\nList end";
	while(temp->prev != NULL){
		cout<<"\n"<<i<<". "<<temp->value;
		i++;
		temp = temp->prev;
	}
	cout<<"\n"<<i<<". "<<temp->value;
	cout<<"\nList start\n";
}
//menu : independent function
void menu(){
	cout<<"\n1 : insert element";
	cout<<"\n2 : delete element";
	cout<<"\n3 : display elements";
	cout<<"\n4 : reverse display elements";
	cout<<"\n5 : search element"<<endl;
}
//singleton class structure
int main() {
	List object;
	int choice;
	menu();
	int cont = 1;
	while(cont){
		cout<<"CHOICE : ";
		cin>>choice;
		switch(choice){
		case 1: object.insert();
				break;
		case 2: object.remove();
					break;
		case 3: object.display();
					break;
		case 4: object.revdisplay();
					break;
		case 5: if(object.search())
					cout<<"\nFound";
				else
					cout<<"\nNot found";
				break;
		default : break;
		}
		cout<<"\nContinue?(1/0)";
		cin>>cont;
	}
	cout<<"~program terminated";
	return 0;
}
