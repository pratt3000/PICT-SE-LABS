//============================================================================
// Name        : a_8_infix_postfix.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
class Node{
	char ch;
	Node* link;
public:
	Node(char);
	friend class Stack;
};
Node::Node(char c){
	ch=c;
	link=NULL;
}
class Stack{
	Node *top;
public:
	Stack(){
		top=NULL;
	}
	int push(char);
	char pop();
	int isEmpty();
	void display();
	int peek(char);
	void free();
	char rettop(){
		return top->ch;
	}
};
int Stack::isEmpty(){
	if(top==NULL)
		return 1;
	else
		return 0;
}
int Stack::peek(char c){
	if(c==top->ch)
		return 1;
	else
		return 0;
}
void Stack::display(){
	Node* ptr=top;
	if(top==NULL){
		cout<<"\nStack is Empty";
		return;
	}
	while(ptr!=NULL){
		cout<<ptr->ch<<" ";
		ptr=ptr->link;
	}
	cout<<"\n";
}
int Stack::push(char c){
	Node* temp;
	temp=new Node(c);
	temp->link=top;
	top=temp;
	return 1;
}
char Stack::pop(){
	Node* temp;
	char c;
	if(top==NULL){
		cout<<"\nStack is Empty";
		return 0;
	}
	else{
		c = top->ch;
		temp=top;
		top=top->link;
		delete temp;
		return c;
	}
}
void Stack::free(){
	top=NULL;
}

class inpo{
	char expr[1000],final[1000];
	int n;
public:
	int priority();
	int priority2(int i);
	void input();
	void expdisplay();
	//void convert();
	void fillstack();
	Stack s;
};
void inpo :: input(){
	cout<<"\nNO. OF VARIABLES : ";
	cin>>n;
	cout<<"\nINPUT EXPRESSION : ";
	cin>>expr;
	return;
}
int inpo :: priority2(int i){
	if(expr[i] == '/' || expr[i] == '*')
			return 2;
	else if(expr[i] == '^')
			return 3;
	else if(expr[i] == '+' ||  expr[i] == '-')
			return 1;
	else if(expr[i] == '(')
			return 0;
	return -1;
}
int inpo :: priority(){
	if(s.peek('/') || s.peek('*'))
		return 2;
	else if(s.peek('^'))
		return 3;
	else if(s.peek('+') ||  s.peek('-'))
		return 1;
	else if(s.peek('('))
		return 0;
		return -1;
}
void inpo :: fillstack(){
	int i,j=0;
	s.push('#');
	for(i=0; expr[i] != '\0'; i++){
		//if(s.peek('(') || s.peek('+') || s.peek('-') || s.peek('^') || s.peek('/') || s.peek('*')  )
		if(expr[i] == '(' || expr[i] == '-' || expr[i] == '^' || expr[i] == '/' || expr[i] == '*' ||expr[i] == '+')
		{

			while(priority() >= priority2(i)){
				final[j] = s.rettop();
				final[j]= s.pop();
				j++;
			}
			s.push(expr[i]);
		}
		else if(expr[i] == ')'){
			while(!s.peek('(')){
				final[j] = s.pop();
				j++;
			}
		}
		else{
			final[j] = expr[i];
			j++;
	    }
	}
	while(!s.isEmpty()){
		final[j] = s.pop();
		j++;
	}
	final[j-1] = '\0';
}
void inpo :: expdisplay(){
	cout<<final;
}

int main() {
	inpo obj;
	obj.input();
	obj.fillstack();
	obj.expdisplay();

	return 0;
}
