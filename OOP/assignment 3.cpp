//============================================================================
// Name        : assignment.cpp
// Author      : prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class Quadratic{
	float a,b,c;
public:
	Quadratic(){a=0;b=0;c=0;}
	Quadratic operator+(Quadratic &ob1){
		Quadratic obj;
		obj.a = a + ob1.a;
		obj.b = b + ob1.b;
		obj.c = c + ob1.c;
		return obj;
	}
	friend istream & operator>>(istream &in, Quadratic &c){
		in>>c.a;
		in>>c.b;
		in>>c.c;
		return in;
	}
	friend ostream & operator<<(ostream &ot, Quadratic &c){
			ot<<c.a<<"x^2 + "<<c.b<<"x + "<<c.c<<endl;
			return ot;
		}
	float value(int x){
		return(x*x*a  + b*x + c);
	}
	float value1(int x){
			return(x*x*a  + b*x + c);
		}
	void calc(){
		cout<<"\nFIRST:\n";
		if(b*b - 4*a*c>=0 && a!=0){
		cout<<"root 1 : "<<((-b+ sqrt(b*b - 4*a*c))/2*a)<<endl;
		cout<<"root 2 : "<<((-b- sqrt(b*b - 4*a*c))/2*a)<<endl;
		}
		else
				cout<<"complex roots~";
	}
	void calc1(){
		cout<<"\nSECOND:\n";
		if(b*b - 4*a*c>=0 && a!=0){
		cout<<"root 1 : "<<((-b+ sqrt(b*b - 4*a*c))/2*a)<<endl;
		cout<<"root 2 : "<<((-b- sqrt(b*b - 4*a*c))/2*a)<<endl;
		}
		else
			cout<<"complex roots~";
	}

};

int main() {
	Quadratic obj,ob1,ob;
	cout<<"enter quadratic eqn 1 : ";
	cin>>ob;
	cout<<"enter quadratic eqn 2 : ";
	cin>>ob1;
	cout<<"quadratic eqn 1 : ";
	cout<<ob;
	cout<<"quadratic eqn 2 : ";
	cout<<ob1;
	int i=1,o;
	while(i==1){
			cout<<"\noption 1 : addition of poly \noption 2 : insert value in 1st\noption 3 : insert value in 2nd \noption 4 : solve equation ";
			cin>>o;
			switch(o){
				case 1:
						obj=ob+ob1;
						cout<<obj;
						break;
				case 2:
						int x;
						cout<<"enter value of x : ";
						cin>>x;
						cout<<"ANSWER="<<ob.value(x);
						break;
				case 3:
						int y;
						cout<<"enter value of x : ";
						cin>>y;
						cout<<"ANSWER="<<ob1.value1(y);
						break;
				case 4:
						ob.calc();
						ob1.calc1();
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
