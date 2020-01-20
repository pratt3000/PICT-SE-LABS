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
    Node(string name, int fuel){
        down = NULL;
        right = NULL;
        this->name = name;
        this->fuel = fuel;
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
		cout<<endl<<"Enter number of vertices : ";
		cin>>vert;
		cout<<"--------------------------------------------------"<<endl;
		for(int i=0;i<vert;i++){
			cout<<"\nEnter city name : ";
			cin>>name1;
			Node *t = new Node(name1, 0);
			if(start == NULL){
				start = t;
				temp = start;
			}
			else{
				temp->down = t;
				temp = temp->down;
			}
		}
		/*
		cout<<start->name<<start->down->name;
		if(start->down->down == NULL)
			cout<<"fks";
		*/
		cout<<endl<<"--------------------------------------------------"<<endl;
	}
	void initialise_edges(){
		Node *temp, *temp1;
		string connec;
		int fuel1;
		temp = start;
		while(temp != NULL){
			edges = vert+1;
			while(edges >= vert){
				cout<<"\nNo. of connections of "<<temp->name<<" : ";
				cin>>edges;
			}
			while(edges--){
				e:cout<<"Connection of "<<temp->name<<" : ";
				cin>>connec;
				if(!amongEdges(temp, connec) && amongVertices(connec)){
					cout<<"Fuel needed (litres) : ";
					cin>>fuel1;
					cout<<endl;
					temp1 = temp;
					while(temp1->right != NULL)
						temp1 = temp1->right;
					temp1->right = new Node(connec, fuel1);
				}
				else{
					cout<<"******re-enter******"<<endl;
					goto e;
				}
			}
			temp = temp->down;
		}
	}
	bool amongEdges(Node *temp, string connec){
		bool present = 0;
		while(temp != NULL){
			if(temp->name.compare(connec) == 0){
				present = 1;
				break;
			}
			temp = temp->right;
		}
		return present;
	}
	bool amongVertices(string connec){
		Node*temp = start;
		bool present = 0;
		while(temp != NULL){
			if(temp->name.compare(connec) == 0){
				present = 1;
				break;
			}
			temp = temp->down;
		}
		return present;
	}
	void addEdge(){
		string from, to;
		int fuel1;
		cout<<"\nAdding and edge";
		cout<<"\nFROM : ";
		cin>>from;
		cout<<"\nTO : ";
		cin>>to;
		Node *tempdn = start;
		if(amongVertices(from)){
			while(tempdn != NULL){
				if(tempdn->name.compare(from) == 0)
					break;
				tempdn = tempdn->down;
			}
			Node *temprt = tempdn;
			if(!amongEdges(temprt, to)){
				while(temprt->right != NULL){
					temprt = temprt->right;
				}
				cout<<"\nFuel needed (litres) : ";
				cin>>fuel1;
				temprt->right = new Node(to, fuel1 );
			}
			else{
				cout<<"\n******Edge already present******";
			}
		}
		else{
			cout<<"\n******Start vertice not present******";
		}
	}
	void deleteEdge(){
		string from, to;
		int fuel1;
		cout<<"\nAdding and edge";
		cout<<"\nFROM : ";
		cin>>from;
		cout<<"\nTO : ";
		cin>>to;
		Node *tempdn = start;
		if(amongVertices(from)){
			while(tempdn != NULL){
				if(tempdn->name.compare(from) == 0)
					break;
				tempdn = tempdn->down;
			}
			Node *temprt = tempdn, *rebound;
			if(amongEdges(temprt, to)){
				while(temprt != NULL){
					if(temprt->name.compare(to) == 0)
						break;
					rebound = temprt;
					temprt = temprt->right;
				}
				rebound->right = temprt->right;
				delete temprt;
			}
			else
				cout<<"\n******Edge not present******";
		}
		else
			cout<<"\n******Edge not present******";
	}

};


int main() {
	AdjacencyList ob;
	int cont = 1;
	int choice;
	cout<<"\n1 : Initialise directed Graph";
	cout<<"\n2 : Add Edge";
	cout<<"\n3 : Delete Edge";
	cout<<"\n4 : Add Vertice";
	cout<<"\n5 : Delete Vertice";
	cout<<"\n6 : In-degree & Out-degree";
	cout<<"\n7 : Traversal";
	cout<<"\n99 : END"<<endl;
	while(cont){
		cout<<"--- Enter choice :  ";
		cin>>choice;
		cout<<"========================================================="<<endl;
		switch(choice){
			case 1:
				ob.initialise_vertices();
				ob.initialise_edges();
				break;
			case 2:
				ob.addEdge();
				break;
			case 3:
				ob.deleteEdge();
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
