//============================================================================
// Name        : a_5.cpp
// Author      : prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
class AdjacencyMatrix{
	int **office;
	int ofs;
	int of1, of2;
	int cost;
	int *used;
public:
	void initialize(){
		cout<<"number of offices : ";
		cin>>ofs;
		office = new int *[ofs];
		used = new int [ofs];
		for(int i=0; i<ofs; i++)
			office[i] = new int [ofs];
		for(int i=0; i<ofs; i++){
			used[i] = 0;
			for(int j=0; j<ofs; j++){
				office[i][j] = 0;
			}
		}

	}
	void addEdges(){
		while(1){
			cout<<"office no. 1 & 2 : ";
			cin>>of1>>of2;
			cout<<"Cost (-1 for exit): ";
			cin>>cost;
			if(cost == -1)
				break;
			office[of1-1][of2-1] = cost;
			office[of2-1][of1-1] = cost;
		}
	}
	void krushkals(){
		int min = INT_MAX;
		for(int i=0; i<ofs; i++){
			for(int j=i; j<ofs; j++){

			}
		}
	}
};
int main() {
	AdjacencyMatrix ob;
	ob.initialize();
	int cont = 1;
	int choice;
	cout<<"\n01 : Add edge";	//done
	cout<<"\n99 : END"<<endl;
	while(cont){
		cout<<"--- Enter choice :  ";
		cin>>choice;
		cout<<"====================================="<<endl;
		switch(choice){
			case 1:ob.addEdges();
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
