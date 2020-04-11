//=================================================================================================
// Name        : assignment.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Develop an object oriented program in C++ to create a database of student
//				 information system containing the following information: Name, Roll number, Class,
//				 division, Date of Birth, Blood group, Contact address, telephone number,
//				 driving license no. etc
//				 Construct the database with suitable member functions
//				 for initializing and destroying the data viz constructor, default constructor,
//				 Copy constructor, destructor, static member functions, friend class, this pointer,
//				 inline code and dynamic memory allocation operators-new and delete.
//=================================================================================================

#include <bits/stdc++.h>
using namespace std;
class student {
	static int count;
	string roll,name,cls,division,birth,bloodg,contact,tele,license;
	void get();
public:
	friend class student_personal;
	student();
	student(string,string,string,string,string,string,string,string,string);
	student(student &s);
	~student();
	void getdata();
	static int getcount(){
		return count;
	}
};
void student :: get(){
	cout<<endl<<contact;
}
student :: student(){
	roll = "N/A";
	name = "N/A";
	cls = "N/A";
	division = "N/A";
	birth = "N/A";
	bloodg = "N/A";
	contact = "N/A";
	tele = "N/A";
	license = "N/A";
	cout<<"\nbasic constructor";
	count++;
}
student :: student(string roll,string name,string cls,string division,string birth,string bloodg,string contact,string tele,string license){
	this-> roll = roll;
	this-> name = name;
	this-> cls = cls;
	this-> division = division;
	this-> birth = birth;
	this-> bloodg = bloodg;
	this-> contact = contact;
	this-> tele = tele;
	this-> license = license;
	cout<<"\nparameterised constructor";
	count++;
}
student :: student(student &s){
	roll = s.roll;
	name = s.name;
	cls = s.cls;
	division = s.division;
	birth = s.birth;
	bloodg = s.bloodg;
	contact = s.contact;
	tele = s.tele;
	license = s.license;
	cout<<"\ncopy constructor";
	count++;
}
student :: ~student(){
	cout<<"\ndestruction";
	count--;
}
void student:: getdata(){
		cout<<"enter details\n";
		cout<<"\nroll no:"; cin>>roll;
		cout<<"\nname:"; cin>>name;
		cout<<"\nclass:"; cin>>cls;
		cout<<"\ndivision:"; cin>>division;
		cout<<"\nbirth date:"; cin>>birth;
		cout<<"\nblood group:"; cin>>bloodg;
		cout<<"\ncontact:"; cin>>contact;
		cout<<"\ntelephone no.:"; cin>>tele;
		cout<<"\nlicense no.:"; cin>>license;
}
class student_personal{
	student obj;
public:
	void display(student &s2);

};
void student_personal :: display(student &s2){
	cout<<"\nroll no:"<<s2.roll;
	cout<<"\name:"<<s2.name;
	cout<<"\nclass:"<<s2.cls;
	cout<<"\ndivision:"<<s2.division;
	cout<<"\nbirth date:"<<s2.birth;
	cout<<"\nblood group:"<<s2.bloodg;
	cout<<"\ncontact:"<<s2.contact;
	cout<<"\ntelephone no.:"<<s2.tele;
	cout<<"\nlicense no.:"<<s2.license;
	//ob.get();
}
int student :: count=0;

int main() {
	int n;
	cout<<"enter no.:";		cin>>n;
	student *ob[n];
	student_personal bj;
	for(int i=0;i<n;i++){
		ob[i]=new student();
		ob[i]->getdata();
		bj.display(*ob[i]);
	}
	delete []ob;
	//cout<<endl<<"count="<<ob2.getcount();
	return 0;
}
