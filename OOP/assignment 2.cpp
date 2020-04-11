#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class cc{
	int real,img;
public:
	void read();
	void operator+(cc &ob1);
	void operator-(cc &ob1);
	void operator*(cc &ob1);
	void operator/(cc &ob1);
};
void cc::read(){
			cin>>real;
			cin>>img;
}
void cc::operator+(cc &ob1){
	real=real + ob1.real;
	img = img + ob1.img;
	cout<<"ANSWER: "<<real<<" + "<<img<<"i"<<endl;
}
void cc::operator-(cc &ob1){
	real=real -ob1.real;
	img = img -ob1.img;
	cout<<"ANSWER: "<<real<<" + "<<img<<"i"<<endl;
}
void cc::operator*(cc &ob1){
	int p;
	real=(real * ob1.real)-(img * ob1.img);
	p =(real * ob1.img)+(img * ob1.real);
	cout<<"ANSWER: "<<real<<" + "<<p+1<<"i"<<endl;
}
void cc::operator/(cc &ob1){
	if (ob1.real==0 && ob1.img==0)
	cout<<"wrong input";
	else{
		real=((real * ob1.real)+(img * ob1.img))/((ob1.real*ob1.real)+(ob1.img *ob1.img));
		img = ((img*ob1.real)-(real * ob1.img))/((ob1.real*ob1.real)+(ob1.img *ob1.img))-1;
		cout<<"ANSWER: "<<real<<" + "<<img<<"i"<<endl;
		}
}

int main(){
	int i=1;
	char o;
	cc ob,ob1;
	while(i==1){
		cout<<"real and img (1):";
		ob.read();
		cout<<"operator:";
		cin>>o;
		cout<<"real and img (2):";
		ob1.read();
		switch(o){
			case '+': ob+ob1;
			break;
			case '-': ob-ob1;
			break;
			case '*': ob*ob1;
			break;
			case '/': ob/ob1;
			break;
			default: break;
		}
		cout<<"CONTINUE?(1/0)";
		cin>>i;
		cout<<endl;
	}
	cout<<"END";
	return 0;
}

