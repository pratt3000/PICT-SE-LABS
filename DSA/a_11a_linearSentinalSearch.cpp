//============================================================================
// Name        : a_11a_linearSentinalSearch.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
class student{
	int n;
	string name[1000];
	int rollno[1000];
public:
	void input(){
		cout<<"ENTER NO. OF STUDENTS : ";
		cin>>n;
		for(int i = 0; i<n; i++){
			cout<<"\nNAME : ";
			cin>>name[i];
			cout<<"ROLL NO. : ";
			cin>>rollno[i];
		}
	}
	int linearsearch(int rn){
		for(int i =0; i<n; i++){
			if(rollno[i] == rn)
				return i;
		}
		return -1;
	}
	int sentinelsearch(int rn){
		rollno[n] = rn;
		int i;
		for(i= 0; rollno[i] != rn; i++);
		if(i == n)
			return -1;
		return i;
	}
	int binarysearch(int rn){
				int start = 0,end = n-1 ,mid;
				int flag = -1;
				while(start != end){
					mid = (start + end)/2;
					if(rn < rollno[mid])
						end = mid-1;
					else if(rn > rollno[mid])
						start = mid + 1;
					else if(rn == rollno[mid]){
						flag = mid;
						break;
					}
				}
				if(rn == rollno[n-1])
					flag = n-1;
				return flag;
	}
	int fibonaccisearch(int rn){
		int len = n;
		int pos;
		int flag = -1;
		int c = 0;
		while(len > 0 ){
			pos = smallClosestfibo( len );
			if(rn < rollno[c + pos])
				len = pos + c;
			else if(rn > rollno[c + pos]){
				len = len - pos - c;
				c = c + pos;
			}
			else if(rn == rollno[c + pos]){
				flag = c + pos;
				break;
			}
		}
		return flag;
	}
	int smallClosestfibo(int len){
		int f1 = 1, f2 = 1, f3;
		while(f3 <= len ){
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		return f1;
	}
	void display(int opt){
		cout<<"\nFOUND";
		cout<<"\nNAME : "<<name[opt]<<"    ROLL NO. : "<<rollno[opt];

	}
	void displaywhole(){
		cout<<"\nLIST IS :";
		for(int i =0;i<n;i++)
			cout<<"\nNAME : "<<name[i]<<"    ROLL NO. : "<<rollno[i];
		cout<<endl;
	}
	void bubblesort(){
		for(int i =0 ; i<n; i++){
			for(int j=i; j<n; j++){
				if(rollno[i] > rollno[j]){
					swap(rollno[i], rollno[j]);
					swap(name[i], name[j]);
				}
			}
		}
	}
};
int main() {
	student ob;
	int i=1;
	int opt;
	int rn;
	int ch;
	ob.input();
	ob.bubblesort();
	ob.displaywhole();
	while(i){
		cout<<"\n1: LINEAR SEARCH"
			<<"\n2: SENTINAL SEARCH"
			<<"\n3: BINARY SEARCH"
			<<"\n4: FIBONACCI SEARCH"
			<<"\n5: DISPLAY LIST OF STUDENTS";

		cout<<"\nCHOICE : ";
		cin>>ch;

		switch(ch){
		case 1:	cout<<"TO SEARCH : ";
				cin>>rn;
				opt = ob.linearsearch(rn);
				if(opt == -1)
					cout<<"NOT FOUND";
				else
					ob.display(opt);
				break;
		case 2:	cout<<"TO SEARCH : ";
				cin>>rn;
				opt = ob.sentinelsearch(rn);
				if(opt == -1)
					cout<<"NOT FOUND";
				else
					ob.display(opt);
				break;
		case 3:	cout<<"TO SEARCH : ";
				cin>>rn;
				opt = ob.binarysearch(rn);
				if(opt == -1)
					cout<<"NOT FOUND";
				else
					ob.display(opt);
				break;
		case 4:	cout<<"TO SEARCH : ";
				cin>>rn;
				opt = ob.fibonaccisearch(rn);
				if(opt == -1)
					cout<<"NOT FOUND";
				else
					ob.display(opt);
				break;
		case 5: ob.displaywhole();
				break;
		default:break;
		}
		cout<<"\nCONTINUE(1/0)?";
		cin>>i;
	}
	return 0;
}
