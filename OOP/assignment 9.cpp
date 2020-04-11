//============================================================================
// Name        : commandLineArguments.cpp
// Author      : Prathamesh
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]){
	if(argc < 4){
		cout<<"\nNon-valid arguments";
		exit(1);
	}
    ifstream in(argv[1]);
	if(!in){
		cout<<"Error in opening file";
		exit(1);
	}
	string replacedata = "";
    string s2 = argv[2];
	string data;
	unsigned int found;
	while(in){
		getline(in,data);
        found = data.find(s2);
		while(data.find(s2) < 500){
			data.replace(found, s2.size(), argv[3]);
			found = data.find(s2);
		}
		replacedata = replacedata + data + "\n";
	}
	in.close();
    cout<<replacedata;
    ofstream ob;
    ob.open(argv[1], ios::out|ios::trunc);
    ob<<replacedata;
	return 0;
}
