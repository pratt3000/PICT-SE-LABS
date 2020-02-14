//============================================================================
// Name        : a_6.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
class HashTable{
	int asciiSum;
	string feed;
	string dict[89];
	int choice;
public:
	HashTable(){
		asciiSum = 0;
		choice = 0;
	}
	void chooseType(){
		cout<<"\nChoose Hashing type : \n1.non-replacement\n2.replacement";
		cout<<"choice : ";
		cin>>choice;
		insert();
	}
	void insert(){
		int cont = 1;
		do{
			cout<<"\nEnter word to store : ";
			cin>>feed;
			asciiSum = 0;
			for(int i=0; feed[i] != '\0'; i++)
				asciiSum += (i+3)*feed[i];
			asciiSum /= 89;
			if(choice == 1){
				for(int i=asciiSum; i<89; i++){
					if(dict[i].length() == 0)
						dict[asciiSum] = feed;
						break;
				}
			}
			else if(choice == 2){
				string temp = dict[asciiSum];
				dict[asciiSum] = feed;
				for(int i=asciiSum+1; i<89; i++){
					if(dict[i].length() == 0)
						dict[asciiSum] = temp;
						break;
				}
			}
			cout<<"\nContinue(1/0) : ";
			cin>>cont;
		}while(cont);
	}
	void initialiseSearch(){
		cout<<"\nEnter string to search : ";
		string findOut;
		cin>>findOut;
		int idx = findIndex(findOut);
		if(idx == -1)
			cout<<"\nNot Found";
		else{
			cout<<"\nFound";
			cout<<idx<<"  "<<dict[idx];
		}
	}
	int findIndex(string findOut){
		int idx = -1;
		asciiSum = 0;
		for(int i=0; feed[i] != '\0'; i++)
			asciiSum += (i+3)*findOut[i];
		asciiSum /= 89;
		for(int i=asciiSum; i<89; i++){
			if(findOut.compare(dict[i]) == 0){
				idx = i;
				break;
			}
		}
		return idx;
	}
	void deleteEntry(){
		string findOut;
		cout<<"\nEnter entry to delete";
		cin>>findOut;
		int idx = findIndex(findOut);
		if(idx == -1)
			cout<<"\nNot Found";
		else{
			cout<<"\nFound";
			dict[idx] = "";
		}
	}
};
int main() {
	HashTable ob;
	int cont = 1;
	int choice;
	cout<<"\n01 : Add new entries";
	cout<<"\n02 : Find entry";
	cout<<"\n03 : Delete entry";
	cout<<"\n99 : END"<<endl;
	while(cont){
		cout<<"--- Enter choice :  ";
		cin>>choice;
		cout<<"====================================="<<endl;
		switch(choice){
			case 1:ob.chooseType();
				break;
			case 2:ob.initialiseSearch();
				break;
			case 3:ob.deleteEntry();
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
