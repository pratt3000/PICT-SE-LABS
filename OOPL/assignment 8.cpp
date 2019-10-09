//============================================================================
// Name        : fileHandling1.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class student{
	int age;
	char name[100];
public:
	void get(){
		cin>>age>>name;
	}
	void put(){
		cout<<age<<"   "<<name;
	}
};

int main(){
	student s;
	fstream f;
	f.open("binary.out",ios::binary|ios::in|ios::out|ios::app);
	s.get();
	f.write((char*)&s, sizeof(s));
	f.read((char*)&s, sizeof(s));
	s.put();
	f.close();
	return 0;
}
