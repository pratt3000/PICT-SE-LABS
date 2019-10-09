//============================================================================
// Name        : a_8_revised.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define MAX 256
template<class T>
class Stack{
	T arr[MAX];
	int top;
public:
	Stack(){
		top=-1;
	}


	void push(T a){
		top++;
		if(top<MAX)
			arr[top]=a;
		else{
			cout<<"Stack is FULL";
			top--;
		}
	}
	T peek(){
		if(top==-1)
			return '#';
		return arr[top];
	}


	void pop(){
		if(top==-1){
			cout<<"Stack is EMPTY";
			return;
		}
		top--;
	}


	bool isEmpty(){
		return top==-1;
	}


	bool isFull(){
		return top==MAX;
	}


	void display(){
		for(int i=top;i>=0;i--)
			cout<<arr[i]<<" ";
	}


	~Stack(){
		top=-1;
	}
};




class Expression{
	char str[MAX];
public:
	Expression(){
		str[0]='\0';
	}
	void read();
	void display();
	void append(char);
	int getLength();
	int precedence(char);
	int isOperator(char);
	float evaluate();
	Expression infixToPostfix();
	~Expression(){
		str[0]='\0';
	}
};
int Expression::getLength(){
	int i;
	for(i=0;str[i]!='\0';i++);
	return i;
}
void Expression::read(){
	cout<<"\nEnter Infix Expression (without space): ";
	cin>>str;
}
void Expression::display(){
	cout<<str;
}
void Expression::append(char c){
	int i;
	for(i=0;str[i]!='\0';i++);
	str[i]=c;
	str[i+1]='\0';
}
int Expression::isOperator(char op){
	if(op=='^'||op=='*'||op=='/'||op=='+'||op=='-')
		return 1;
	else
		return 0;
}
int Expression::precedence(char op){
	if(op=='^')
		return 3;
	else if(op=='*'||op=='/')
		return 2;
	else if(op=='+'||op=='-')
		return 1;
	else
		return 0;
}
Expression Expression::infixToPostfix(){
	Stack<char> s;
	char symbol,top;
	int l=getLength();
	Expression exp;
	s.push('(');
	str[l]=')';
	str[l+1]='\0';
	for(int i=0;str[i]!='\0';i++){
		symbol=str[i];
		if(symbol=='('){
			s.push('(');
		}
		else if(symbol==')'&&!s.isEmpty()){
			while(s.peek()!='('){
				exp.append(s.peek());
				s.pop();
			}
			s.pop();
		}
		else if(isOperator(symbol)){
			top=s.peek();
			if(precedence(top)<precedence(symbol)){
				s.push(symbol);
			}
			else{
				while(precedence(top)>=precedence(symbol)){
					exp.append(s.peek());
					s.pop();
					top=s.peek();
				}
				s.push(symbol);
			}
		}
		else if(isalpha(symbol)||isdigit(symbol)){
			exp.append(symbol);
		}
		else{
			exp.str[0]='\0';
			break;
		}
	}
	if(!s.isEmpty()){
		exp.str[0]='\0';
	}
	return exp;
}
float Expression::evaluate(){
	Stack<float> s;
	char symbol,top;
	float a,b;
	for(int i=0;str[i]!='\0';i++){
		symbol=str[i];
		if(isalpha(symbol)){
			cout<<"Enter Value of "<<symbol<<": ";
			cin>>a;
			s.push(a);
		}
		else if(isdigit(symbol)){
			a=symbol-'0';
			s.push(a);
		}
		else if(isOperator(symbol)&&!s.isEmpty()){
			b=s.peek();
			if(s.isEmpty()){
				cout<<"*Undefined*";
				cout<<"\n*Operator(s) MisMatch";
				return 0;
			}
			s.pop();
			a=s.peek();
			if(s.isEmpty()){
				cout<<"*Undefined*";
				cout<<"\n*Operator(s) MisMatch-";
				return 0;
			}
			s.pop();
			switch(symbol){
				case '+': s.push(a+b);
							break;
				case '-': s.push(a-b);
							break;
				case '*': s.push(a*b);
							break;
				case '/': s.push(a/b);
							break;
			}
		}
		else{
			cout<<"*Undefined*";
			cout<<"\n*Operator(s) MisMatch";
			return 0;
		}
	}
	cout<<str<<" = ";
	return s.peek();
}
int main(){
	Expression infix,postfix;
	int rep=1;
	while(rep){
		infix.read();
		postfix=infix.infixToPostfix();
		if(postfix.getLength()){
			cout<<"Postfix Expression is: ";
			postfix.display();
			cout<<"\n\nEvaluation: ";
			cout<<"\n";
			cout<<postfix.evaluate();
		}
		else
			cout<<"\nInvalid Infix Expression!";
		cout<<"\n\n---------------------------------------------------------";
		cout<<"\nDo You Want to Enter Another Expression(0/1): ";
		cin>>rep;
	}
	cout<<"\n--------------------------END----------------------------\n";
	return 0;
}
