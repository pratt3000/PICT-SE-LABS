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
public:
	friend class node;
	Tree(){
		q = NULL;
		root = NULL;
	}
	void mirror(Node *root){
		if(root){
			mirror(root->left);
			mirror(root->right);
			swap(root->right, root->left);
		}
	}
	void mirrorInitialize(){
		mirror(root);
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
				cout<<"Goto left or right node?(0/1) : ";
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
	void eraseTree(Node *rt){
		if(rt != NULL){
			eraseTree(rt->left);
			eraseTree(rt->right);
			delete(root);
		}
	}
	void initializeEraseTree(){
		eraseTree(root);
	}
	void assignTreeInitialize(){
		Tree obnew;
		obnew.root->value = root->value;
		treeInitialize(root, obnew.root);
	}
	void treeInitialize(Node *rt, Node *rt1){
		if(rt != NULL){
			rt1->left  = rt->left;
			rt1->right = rt->right;
			treeInitialize(rt->left, rt1->left);
			treeInitialize(rt->right, rt1->right);
		}
		cout<<"\nCHECK : \n";
		inorder_recursive(rt);
		cout<<endl;
		inorder_recursive(rt1);
	}




};
int main() {
	int flag = 0;
	Tree obj;
	int cont = 1;
	int val;
	int choice;
	while(cont){
		cout<<"\n1:ADD NODE ";				//DONE
		cout<<"\n2:IN-ORDER";				//DONE
		cout<<"\n3:PRE-ORDER";				//DONE - no chk done
		cout<<"\n4:POST-ORDER";				//DONE - no chk done
		cout<<"\n5:MIRROR TREE";			//DONE - no chk done
		cout<<"\n6:ERASE TREE";				//DONE - no chk done
		cout<<"\n7:ASSIGN TO ANOTHER TREE";	//DONE - NOT BY OVERLOADING
		cout<<"\n8:CHECK IF EQUAL";
		cout<<"\n9:PRINT LEVEL WISE";
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
			case 5:
				obj.mirrorInitialize();
				break;
			case 6:
				obj.initializeEraseTree();
				break;
			case 7:
				obj.assignTreeInitialize();
				break;
			case 8:						//remaining
				flag = 1;
				goto c;
				obj.checkEqual()
			case 99:
				cont = 0;
				break;
			default:break;
		}
	}
	cout<<"\n~ TERMINATED";
	return 0;
}
