//============================================================================
// Name        : assignment.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class personal{
	int age;
	string name;
public:
	personal(){
		age=0;
		name=' ';
		cout<<"\npersonal constructor";
	}
	void get(){
		cout<<"\nENTER PERSONAL DETAILS:\n";
		cout<<"NAME:";
		cin>>name;
		cout<<"\nAGE:";
		cin>>age;
	}
	void put(){
		cout<<"\n\n--------------------- DETAILS ---------------------------";
		cout<<"\nNAME:"<<name;
		cout<<"\nAGE:"<<age;
	}
	~personal(){
		cout<<"\npersonal destructor";
	}
};
class professional{
	int exp;
	string sp;
public:
	professional(){
		exp=0;
		sp=' ';
		cout<<"\nprofessional constructor";
	}
	void get(){
		cout<<"ENTER PROFESSIONAL DETAILS:";
		cout<<"\nEXPERIENCE:";
		cin>>exp;
		cout<<"\nSPECIALIZATION:";
		cin>>sp;
	}
	void put(){
		cout<<"\nEXPERIENCE:"<<exp;
		cout<<"\nSPECIALIZATION:"<<sp;
	}
	~professional(){
		cout<<"\nprofessional destructor";
	}
};
class academics{
	int hsc,ssc,ug,pg;
public:
	academics(){
		hsc=0;
		ssc=0;
		ug=0;
		pg=0;
		cout<<"\nacademics constructor";
	}
	void get(){
		cout<<"ENTER ACADEMIC DETAILS:";
		cout<<"\nSSC MARKS:";
		cin>>ssc;
		cout<<"\nHSC MARKS:";
		cin>>hsc;
		cout<<"\nUG MARKS:";
		cin>>ug;
		cout<<"\nPG MARKS:";
		cin>>pg;
	}
	void put(){
		cout<<"\nSSC MARKS:"<<ssc;
		cout<<"\nHSC MARKS:"<<hsc;
		cout<<"\nUG MARKS:"<<ug;
		cout<<"\nPG MARKS:"<<pg;
	}
	~academics(){
		cout<<"\nacademics destructor";
	}
};
class emp: public personal,public professional,public academics{
public:
	emp(){
		cout<<"\nemployee constructor";
	}
	void get(){
		personal::get();
		professional::get();
		academics::get();

	}
	void put(){
		personal::put();
		professional::put();
		academics::put();

	}
	~emp(){
			cout<<"\nemployee destructor";
		}
};
int main(){
	emp *ob = new emp;
	ob->get();
	ob->put();
	delete ob;
	return 0;
}
