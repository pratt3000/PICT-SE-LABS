//============================================================================
// Name        : assignment_7.cpp
// Author      : prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class stak{

public:
	static int top;
	char stk[1000000];
	stak()
	bool isempty();
	char pop();
	void push(char a);
	bool isfull();
};
char stak :: pop(){
	char s = stk[top];
	top = top - 1;
	return s;
}
void stak :: push(char a){
	stk[top] = a;
	top = top + 1;
}
bool stak :: isempty(){
	if(top == -1)
			return 1;
	return 0;
}
bool stak :: isfull(){
	if(top == 10)
			return 1;
	return 0;
}

class expr{
	char st[100],a;
	bool flag;
	stak ob1;
public:
	void input(){
		cout<<"ENTER THE STRING : ";
		cin>>st;
	}
	bool isvalid(){
		flag = 1;
		if(st[0] == ']' || st[0] == ')' || st[0] == '}' )
			flag = 0;
		for(int i = 0; st[i] != '\0' && flag == 1; i++){
			char ch = st[i];
			switch(ch){
				case '(' :	a = '(';
							ob1.push(a);
							break;
				case ')' :if(ob1.isempty() || ob1.stk[ob1.top] != '(')
							{flag = 0;break;}
						  else
							  ob1.pop();
							break;
				case '{' : 	a = '{';
							ob1.push(a);
							break;
				case '}' :if(ob1.isempty() || ob1.stk[ob1.top] != '{')
							{flag = 0;break;}
						  else
							ob1.pop();
							break;
				case '[' :	a = '[';
							ob1.push(a);
							break;
				case ']' :if(ob1.isempty() || ob1.stk[ob1.top] != '[')
				{ flag = 0;break;}
						  else
							 ob1.pop();
							break;
				default : break;
			}
		}
		return flag;
	}

};

int main() {
	expr obj;
	obj.input();
	bool flag = obj.isvalid();
	if(flag == 1)
			cout<<"\nCORRECT";
	else if(flag == 0)
			cout<<"\nWRONG";
	return 0;
}
