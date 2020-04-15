#include<bits/stdc++.h>
using namespace std;

class Student{
private:
	char name[32];
	char div[8];
	char address[256];
public:
	int rollNo;
	bool deleted;

	Student();
	void getData();
	void setData(char[],char[]);
	void display();
	void remove();
};

Student::Student(){
	rollNo=0;
	name[0]='\0';
	div[0]='\0';
	address[0]='\0';
	deleted=false;
}

void Student::getData(){
	cout<<"\nEnter Roll No: ",cin>>rollNo;
	cin.ignore();
	cout<<"\nEnter Name: ",cin.getline(name,32);
	cout<<"\nEnter Division: ",cin.getline(div,8);
	cout<<"\nEnter Address: \n",cin.getline(address,256);
}

void Student::setData(char div[8],char address[256]){
	strcpy(this->div,div);
	strcpy(this->address,address);
}

void Student::display(){
	cout<<"\n-------------------------------------------------------------------------------------";
	cout<<"\n\t\t\tStudent Profile:";
	cout<<"\n-------------------------------------------------------------------------------------";
	cout<<"\nRoll No: "<<rollNo;
	cout<<"\nName: "<<name;
	cout<<"\nDivision: "<<div;
	cout<<"\nAddress:\n\t"<<address;
	cout<<"\n-------------------------------------------------------------------------------------\n";
}

void Student::remove(){
	deleted=true;
}
