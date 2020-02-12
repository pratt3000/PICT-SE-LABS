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
	int used[100][2];
public:
	void initialize(){
		cout<<"number of offices : ";
		cin>>ofs;
		office = new int *[ofs];
		for(int i=0; i<ofs; i++)
			office[i] = new int [ofs];
		for(int i=0; i<ofs; i++){
			used[i][1] = 0;
			used[i][0] = INT_MAX;
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
		int current = 0;
		int min = INT_MAX;
		cout << "\nstart from 0";
		cout << "link1" << "  " << cost << "  " << "link2";
		for(int i=0; i<ofs; i++){
			if (used[current][0] > 0) {
				used[current][0] = -1;
				for(int j=0; j<ofs; j++){	
					if (office[current][j] > 0) {
						if (office[current][j] < used[j][0]) {
							used[j][0] = office[current][j];
							used[j][1] = current;
						}
					}
				}
				int new = minOfUsedIndex();
				if (new == -1)
					break;
				cout << new << "  " << office[current][new] << "  " << current;
				current = new;
			}
		}
	}
};
int minOfUsedIndex() {
	int min = INT_MAX;
	int minIndex;
	for (int i = 0; i < ofs; i++) {
		if (used[i][0] > 0) {
			if (used[i][0] < min) {
				min = used[i][0];
				minIndex = i;
			}
		}
	}
	if (min == INT_MAX) {
		return -1;
	}
	return minIndex;
}
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
