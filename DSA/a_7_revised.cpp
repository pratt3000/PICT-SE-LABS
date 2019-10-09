#include<bits/stdc++.h>
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
	int pop();
	int isEmpty();
	void display();
	int peek(char);
	void free();
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
int Stack::pop(){
	Node* temp;
	if(top==NULL){
		cout<<"\nStack is Empty";
		return 0;
	}
	else{
		temp=top;
		top=top->link;
		delete temp;
		return 1;
	}
}
void Stack::free(){
	top=NULL;
}
class Expression{
	string str;
public:
	void read(string);
	void display();
	bool isValid();
};
void Expression::read(string exp){
	str=exp;
}
void Expression::display(){
	cout<<"\n"<<str;
}
bool Expression::isValid(){
	Stack s;
	if(str[0]=='}'||str[0]==')'||str[0]==']'){
		return 0;
	}
	for(int i=0;str[i]!='\0';i++){
		if(str[i]=='{')
			s.push(str[i]);
		else if(str[i]=='[')
			s.push(str[i]);
		else if(str[i]=='(')
			s.push(str[i]);
		if(!s.isEmpty()){
			if(str[i]==')'&&s.peek('('))
				s.pop();
			else if(str[i]==')'&&!s.peek('('))
				return 0;
			if(str[i]=='}'&&s.peek('{'))
				s.pop();
			else if(str[i]=='}'&&!s.peek('{'))
				return 0;
			if(str[i]==']'&&s.peek('['))
				s.pop();
			else if(str[i]==']'&&!s.peek('['))
				return 0;
		}
		else if(s.isEmpty()){
			if(str[i]=='}'||str[i]==')'||str[i]==']'){
				return 0;
				break;
			}
		}
	}
	if(s.isEmpty())
		return 1;
	else
		return 0;
}
int main(){
	int rep=1;
	while(rep){
		Expression exp;
		string s;
		cout<<"\nEXPRESSION: ";
		cin>>s;
		exp.read(s);
		if(exp.isValid())
			cout<<"\nCORRECT";
		else
			cout<<"\nWRONG";
		cout<<"\n----------------------------------------------------------------------------";
		cout<<"\nCONTINUE? (0/1): ";
		cin>>rep;
	}
	cout<<"\n~END";
	return 0;
}
