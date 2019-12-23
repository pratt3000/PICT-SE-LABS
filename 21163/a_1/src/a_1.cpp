//============================================================================
// Name        : a_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
class Node{
	Node *left, *right;
	int value;
public:
	Node(int val){
		left = NULL;
		right = NULL;
		value = val;
	}
	friend class Tree;
};
class Tree{
	Node *q, *root;
	friend class node;
public:
	Tree(){
		q = NULL;
		root = NULL;
	}
	void traversal(int choice){
		if(choice == 0)
			inorder_recursive(root);
		if(choice == 1)
			preorder_recursive(root);
		if(choice == 2)
			postorder_recursive(root);
	}
	void add(int data){
		bool side;
		if(root == NULL){
			root = new Node(data);
		}
		else{
			q=root;
			while(1){
				cout<<"Goto left or right node?(1/0) : ";
				cin>>side;
				if(side == 1 ){
					if(q->right != NULL)
						q = q->right;
					else{
						cout<<"\nNULL node found/";
						q->right = new Node(data);
						break;
					}
				}
				else if(side == 0){
					if(q->left != NULL)
						q = q->left;
					else{
						cout<<"\nNULL node found/";
						q->left = new Node(data);
						break;
					}
				}
			}
		}
	}
	void inorder_recursive(Node *rt){
		if(rt != NULL){
			inorder_recursive(rt->left);
			cout<<rt->value << " ";
			inorder_recursive(rt->right);
		}
	}
	void preorder_recursive(Node *rt){
		if(rt != NULL){
			cout<<rt->value<< " ";
			inorder_recursive(rt->left);
			inorder_recursive(rt->right);
		}
	}
	void postorder_recursive(Node *rt){
		if(rt != NULL){
			inorder_recursive(rt->left);
			inorder_recursive(rt->right);
			cout<<rt->value<<" ";
		}
	}
	void inorder(){
		stack <Node*> st;
		q = root;
		int flag = 0;
		while(flag == 0){
				if(q != NULL){
					st.push(q);
					q = q->left;
				}
				else if(!st.empty()){
					q = st.top();
					st.pop();
					cout<<q->value<<" ";
					q = q->right;
				}
				else{
					flag = 1;
				}
		}
	}
	void preorder(){
		stack <Node*> st;
		q = root;
		int flag = 0;
		while(flag == 0){
				if(q != NULL){
					cout<<q->value<<" ";
					st.push(q);
					q = q->left;
				}
				else if(!st.empty()){
					q = st.top();
					st.pop();
					q = q->right;
				}
				else{
					flag = 1;
				}
		}
	}
	void postorder(){
		stack <Node*> st;
		q = root;
		Node *s;
		int flag = 0;
		while(flag == 0){
			if(q != NULL){
				st.push(q);
				q = q->left;
			}
			else if(!st.empty()){
				q = st.top();
				st.pop();
				if(q->right == NULL){
					cout<<q->value<<" ";
				}
				else{
					st.push(q);
					q = q->right;
				}
			}
			else{
				flag = 1;
			}
		}
	}
};
int main() {
	Tree obj;
	int cont = 1;
	int val;
	int choice;
	while(cont){
		cout<<"\n1:ADD NODE ";
		cout<<"\n2:IN-ORDER";
		cout<<"\n3:PRE-ORDER";
		cout<<"\n4:POST-ORDER";
		cout<<"\n99:END";
		cout<<"\n--- enter choice :  ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"enter node value";
				cin>>val;
				obj.add(val);
				break;
			case 2:
				obj.traversal(0);
				cout<<endl;
				obj.inorder();
				break;
			case 3:
				obj.traversal(1);
				cout<<endl;
				obj.preorder();
				break;
			case 4:
				obj.traversal(2);
				cout<<endl;

				//obj.postorder();		//error
				break;
			case 99:
				cont = 0;
				break;
			default:break;
		}
	}
	cout<<"\n~ TERMINATED";
	return 0;
}
