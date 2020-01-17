//============================================================================
// Name        : a_4.cpp
// Author      : prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
class Node{
    Node *down, *right;
    string name;
    int fuel;
public:
    Node(string name){
        down = NULL;
        right = NULL;
        this->name = name;
        fuel = 0;
    }
    friend class AdjacencyList;
};
class AdjacencyList{
	Node *start;
	int vert, edges;
public:
	AdjacencyList(){
		start = NULL;
		vert = 0;
		edges = 0;
	}
	void initialise_vertices(){
		Node *temp;
		string name1;
		cout<<"Enter number of vertices : ";
		cin>>vert;
		for(int i=0;i<vert;i++){
			cout<<"\nEnter city name : ";
			cin>>name1;
			if(start == NULL){
				start = new Node(name1);
				temp = start;
			}
			else{
				temp->down = new Node(name1);
				temp = temp->down;
			}
		}
		cout<<"\nVertices initialised";
	}

	void initialise_edges(){
		Node *temp, *temp1;
		string connec;
		temp = start;
		for(int i=0;i<vert;i++){
			cout<<"\nNo. of connections of "<<temp->name<<" : ";
			cin>>edges;
			for(int j=0; j<edges; j++){
				cout<<"\n"<<j+1<<"th connection of "<<temp->name<<"  : ";
				cin>>connec;
				cout<<"Fuel needed (litres) : ";
				cin>>temp->fuel;
				if(!alreadyPresent(temp, connec)){
					temp1 = temp;
					while(temp1->right != NULL)
						temp1 = temp1->right;
					temp1->right = new Node(connec);
				}
			}
			temp = temp->down;
		}
	}
	bool alreadyPresent(Node *temp, string connec){
		bool present = 0;
		while(temp->right != NULL){
			if(!temp->name.compare(connec) == 0)
				present = 1;
			temp = temp->right;
		}
		return present;
	}
};


int main() {
	AdjacencyList ob;
	int cont = 1;
	int choice;
	cout<<"\n1 : Initialise directed Graph";
	cout<<"\n2 : ";
	cout<<"\n3 : ";
	cout<<"\n4 : ";
	cout<<"\n5 : ";
	cout<<"\n6 : ";
	cout<<"\n7 : ";
	cout<<"\n99 : END"<<endl;
	while(cont){
		cout<<"--- Enter choice :  ";
		cin>>choice;
		switch(choice){
			case 1:
				ob.initialise_vertices();
				ob.initialise_edges();
				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			case 7:

				break;
			case 99:
				cont = 0;
				break;
			default:break;
		}
	}
	cout<<"\n~ TERMINATED";
	return 0;
}
