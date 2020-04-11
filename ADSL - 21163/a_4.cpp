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
    int id, od;
    bool visited;
public:
    Node(string name, int fuel){
        down = NULL;
        right = NULL;
        this->name = name;
        this->fuel = fuel;
        id  = 0;
        od = 0;
        visited = 0;
    }
    friend class AdjacencyList;
};
template <typename T>
class Queue1{
	T data[100];
	int front, back;
public:
	Queue1(){
		front = 50;
		back = 50;
		for(int i=0;i<100;i++)
			data[i] = 0;
	}
	void enqueue(T val){
		data[back] = val;
		back--;
	}
	T dequeue(){
		front--;
		return data[front+1];
	}
	bool isEmpty(){
		if(data[back] == 0 && front == back)
			return 1;
		return 0;
	}
	bool isPresent(T search){
		int present = 0;
		for(int i = front; i<=back; i++){
			if(data[i] == search)
				present = 1;
		}
		return present;
	}
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
		cout<<"\nAdding an edge";
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
		cout<<"\nDeleting an edge";
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
				cout<<"\n******Edge not present******"<<endl;
		}
		else
			cout<<"\n******Edge not present******"<<endl;
	}
	void addVertice(){
		Node* temp = start;
		string tname;
		cout<<"enter new vertice name : ";
		cin>>tname;
		while(temp->down != NULL)
			temp = temp->down;
		Node *temp2 = new Node(tname, 0);
		temp->down = temp2;
	}
	void deleteVertice(){
		cout<<"\nEnter vertice to delete : ";
		string tname;
		cin>>tname;
		int flg = 0;
		if(amongVertices(tname) == 1){
			cout<<"vertice FOUND and deleted"<<endl;
			Node *temp2,*temp = start;
			while(temp->name.compare(tname) != 0){
				temp2 = temp;
				temp = temp->down;
				flg = 1;
			}
			temp2->down = temp->down;
			if(flg == 0){
				start = temp->down;
			}
			temp= start;
			Node *temp3;
			while(temp->down != NULL){
				temp3 = temp;
				temp2 = temp->right;
				while(temp2->right != NULL){
					if(temp2->name.compare(tname) == 0){
						temp3->right = temp2->right;
						break;
					}
					temp3 = temp2;
					temp2 = temp2->right;
				}
				temp = temp->down;
			}
		}
		else{
			cout<<"\nvertice NOT FOUND";
		}
	}
	void calcIODegree(){
		//calculate out degree;
		int tempod = 0;
		Node *temp = start;
		while(temp != NULL){
			Node *temp2 = temp->right;
			while(temp2 != NULL){
				tempod++;
				temp2 = temp2->right;
			}
			temp->od = tempod;
			tempod = 0;
			temp = temp->down;
		}
		//calculate indegree now
		temp = start;
		string find;
		int tempid = 0;
		while(temp != NULL){
			find = temp->name;
			Node* temp2 = start;
			while(temp2!= NULL){
				Node* temp3 = temp2->right;
				while(temp3 != NULL){
					if(temp3->name.compare(find) == 0){
						tempid++;
					}
					temp3 = temp3->right;
				}
				temp2 = temp2->down;
			}
			temp->id = tempid;
			tempid = 0;
			temp = temp->down;
		}
		displayIODegree();
	}
	void displayIODegree(){
		Node *temp =start;
		cout<<"name"<<"\t";
		cout<<"outdegree"<<"\t";
		cout<<"indegree"<<endl;
		while(temp != NULL){
			cout<<temp->name<<"\t\t";
			cout<<temp->od<<"\t\t";
			cout<<temp->id<<endl;
			temp = temp->down;
		}
	}

	bool BFSVisitedCheck(Node *find){
		Node *temp = start;
		while(find->name.compare(temp->name) != 0)
			temp = temp->down;
		if(temp->visited == 1)
			return 1;
		return 0;
	}
	void BFSSetVisited(Node* set){
		Node *temp = start;
		while(set->name.compare(temp->name) != 0 )
			temp = temp->down;
		if(temp != NULL)
			temp->visited = 1;
	}
	void BFSTraversal(){
		Queue1 <Node*> qu;
		qu.enqueue(start);
		start->visited = 1;
		cout<<"----------------BFS------------------- "<<endl;
		while(!qu.isEmpty()){
			Node *temp2 = qu.dequeue();
			temp2->visited = 1;
			cout<<", "<<temp2->name;
			temp2 = temp2->right;
			while(temp2 != NULL){
				if(BFSVisitedCheck(temp2) == 0){
					qu.enqueue(temp2);
					BFSSetVisited(temp2);
				}
				temp2 = temp2->right;
			}
		}
	}
};


int main() {
	AdjacencyList ob;
	int cont = 1;
	int choice;
	cout<<"\n1 : Initialise directed Graph";	//done
	cout<<"\n2 : Add Edge";						//done
	cout<<"\n3 : Delete Edge";					//done
	cout<<"\n4 : Add Vertice";					//done
	cout<<"\n5 : Delete Vertice";				//done
	cout<<"\n6 : In-degree & Out-degree";		//done
	cout<<"\n7 : BFS Traversal";				//a bit remaining
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
				ob.addVertice();
				break;
			case 5:
				ob.deleteVertice();
				break;
			case 6:
				ob.calcIODegree();
				break;
			case 7:
				ob.BFSTraversal();
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
