//============================================================================
// Name        : assignment.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
template<class t>
 t selectionSort( t a[10], t n){
	int min,k;
	for(int i=0;i<n;i++){
		min=a[i];
		k=i;
		for(int j=i+1;j<n;j++){
			if(min>a[j]){
				min=a[j];
				k=j;
			}
		}
		swap(a[i],a[k]);
	}
	return 0;
}


int main() {
	int p=10;
	float n=10;
	int i=1,o;
		while(i){
				cout<<"\noption 1 : INTEGER ARRAY\noption 2 : FLOAT ARRAY\nCHOICE : ";
				cin>>o;
				switch(o){
					case 1:
						int a[10];
						for(int i=0;i<10;i++)		cin>>a[i];
						selectionSort(a , p);
						for(int i=0;i<10;i++)		cout<<a[i]<<"\t";
						break;
					case 2:
						float b[10];
						for(int i=0;i<10;i++)		cin>>b[i];
						selectionSort(b , n);
						for(int i=0;i<10;i++)		cout<<b[i]<<"\t";
							break;
					default: break;
				}
				cout<<"\n\nCONTINUE?(1/0)";
				cin>>i;
				cout<<endl;
			}
		cout<<"\n~terminated";
		return 0;

}
