#include<iostream>
#include<string>
using namespace std;
class calc{
	int a,b,c;
	char o;
public:
	char read();
	void add();
	void sub();
	void mul();
	void div();
};
char calc::read(){
	cout<<"\n enter the number 1:";
			cin>>a;
			cout<<"\n enter the operator:";
			cin>>o;
			cout<<"\n enter the number 2:";
			cin>>b;
			return o;
}
void calc::add(){
	cout<<"\n answer:"<<a+b;
}
void calc::sub(){
	 cout<<"\n answer:"<<a-b;
}
void calc::mul(){
	cout<<"\n answer:"<<a*b;
}
void calc::div(){
	if (b==0)
	cout<<"wrong input";
	else
	cout<<"\n answer:"<<a/b;
}

int main(){
	int i=1;
	char o;
	calc ob;
	while(i==1){
		o=ob.read();
		switch(o){
			case '+': ob.add();
			break;
			case '-': ob.sub();
			break;
			case '*': ob.mul();
			break;
			case '/': ob.div();
			break;
			default: break;
		}
		cout<<"\n continue?(1/0)";
		cin>>i;
	}
	cout<<"END";
	return 0;
}
