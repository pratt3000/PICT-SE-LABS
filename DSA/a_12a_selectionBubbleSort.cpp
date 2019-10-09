//============================================================================
 // Name        : a_12a_selectionBubbleSort.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
class scores{
	int n;
	int score[1000];
public:
	void input(){
			cout<<"ENTER SCORES OF STUDENTS: ";
			cin>>n;
			for(int i = 0; i<n; i++){
				//cout<<"\nNAME : ";
				//cin>>name[i];
				cout<<"SCORE : ";
				cin>>score[i];
			}
	}
	void bubblesort(){
	for(int i =0 ; i<n; i++){
		for(int j=i; j<n; j++){
			if(score[i] > score[j])
				swap(score[i], score[j]);
		}
	}
	}
	void selectionSort(){
		int index;
		int flag = 0;
		for(int i=0;i<n;i++){
			flag = 0;
			int min = score[i];
			for(int j=i; j<n; j++){
				if(min > score[j]){
					min = score[j];
					index = j;
					flag =1;
				}
			}
			if(flag == 1)
				swap(score[i], score[index]);
		}
	}
	void insertionsort(){
		for(int i=1;i<n;i++){
			int j=i-1;
			int key = score[i];
			while(j>=0 && score[j]>key){
				score[j+1] = score[j];
				j--;
			}
			score[j+1] = key;
		}
	}
	void shellsort(){
		for(int gap = n/2; gap > 0; gap /= 2){
		        for (int i = gap; i < n; i += 1){
		            int temp = score[i];
		            int j;
		            for(j = i; j >= gap && score[j - gap] > temp; j -= gap)
		            	score[j] = score[j - gap];
		            score[j] = temp;
		        }
		    }
	}
	void display(){
		cout<<"\n--------SORTED ARRAY---------\n";
		cout<<score[0]<<"  ";
		int dup = score[0];
		for(int i=1;i<n;i++){
			if(dup != score[i] ){
			cout<<score[i]<<"  ";
			dup = score[i];
			}
		}
	}
};
int main() {
	scores ob;
	int i=1;
	int ch;
	ob.input();
	while(i){
			cout<<"\n1: BUBBLE SORT"
				<<"\n2: SELECTION SORT"
				<<"\n3: INSERTION SORT"
				<<"\n4: SHELL SORT";
			cout<<"\nCHOICE : ";
			cin>>ch;
			switch(ch){
			case 1:	ob.bubblesort();
					break;
			case 2:	ob.selectionSort();
					break;
			case 3:	ob.insertionsort();
					break;
			case 4:	ob.shellsort();
					break;
			default:break;
			}
			ob.display();
			cout<<"\nCONTINUE(1/0)?";
			cin>>i;
		}
	return 0;
}
