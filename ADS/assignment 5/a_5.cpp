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
			do{
				cout<<"office no.s (-1 for exit): ";
				cin>>of1>>of2;
				if(of1 == -1 || of2 == -1)
					break;
			}while(of1>=ofs && of2>=ofs);
			cout<<"correct entry";
			cout<<"Cost (-1 for exit): ";
			cin>>cost;
			if(cost == -1)
				break;
			office[of1-1][of2-1] = cost;
			office[of2-1][of1-1] = cost;
		}
	}
	void prims(){
		int current = 0;
		cout << "\nStart from 0"<<endl;
		cout << "link1" << "  " << "link2" << "  " << "cost"<<endl;
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
				int new1 = minOfUsedIndex();
				if (new1 == -1)
					break;
				cout << new1+1 << "  "<< current+1 <<"  "<<office[current][new1] << "  "<<endl;
				current = new1;
			}
		}
	}

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
};

int main() {
	AdjacencyMatrix ob;
	ob.initialize();
	int cont = 1;
	int choice;
	cout<<"\n01 : Add edge";	//done
	cout<<"\n02 prims algo";	//done
	cout<<"\n99 : END"<<endl;
	while(cont){
		cout<<"--- Enter choice :  ";
		cin>>choice;
		cout<<"====================================="<<endl;
		switch(choice){
			case 1:ob.addEdges();
				break;
			case 2:ob.prims();
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
