//============================================================================
// Name        : exceptionHandling.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class exc{
	int age;
	int salary;
	string place;
	bool car;
public:
	exc(){
		age=0;
		salary=0;
		place='NULL';
		car=0;
	}
	void getdata(){
		cout<<"\nENTER AGE:";
		cin>>age;
		cout<<"\nENTER SALARY:";
		cin>>salary;
		cout<<"\nENTER CITY:";
		cin>>place;
		cout<<"\nDO YOU OWN A CAR(1/0)?:";
		cin>>car;

		if((place!="Pune"&& place!="Mumbai"&& place!="Bangalore"&& place!="Chennai")||(car==0)||(salary<50000 || salary>100000)||(age<18 || age>55)){
			throw error();
		}
		else
			cout<<"\nGOOD\n"<<age<<endl<<place<<endl<<salary<<endl<<"\ncar="<<car;
	}
	class error{};
};


int main() {
	int x=1;
	while(x){
	exc a;
	try{
		a.getdata();
	}
	catch(exc::error ){
		cout<<"\nINVALID\n";
	}
	cout<<"CONTINUE(1/0)?";
	cin>>x;
	}
	return 0;
}
