//============================================================================
// Name        : a_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>
using namespace std;
class Node{
	Node *left, *right;
	string keyword, meaning;
public:
	Node(string keyword, string meaning){
		left = NULL;
		right = NULL;
		this->keyword = keyword;
		this->meaning = meaning;
	}
	friend class Tree;
};

class Tree{
	Node *q, *root;
public:
	Tree(){
		q = NULL;
		root = NULL;
	}
	void add(){
		Node *temp,*r;
		string keyword, meaning;
		cout<<"enter keyword : ";
		cin>>keyword;
		cout<<"enter meaning : ";
		cin>>meaning;
		temp = new Node(keyword, meaning);
		q = root;
		r = q;
		int flag = 0;
		if(root == NULL){
			root = temp;
			return;
		}
		else{
			while(q != NULL){
				int comparison = q->keyword.compare( temp->keyword);
				if(comparison > 0){
					r = q;
					q = q-> left;
					flag = 1;
				}
				else if(comparison < 0){
					r = q;
					q = q-> right;
					flag = 2;
				}
				else if (comparison == 0){
					cout<<"\n DOUBLE ENTRY OF KEYWORD"<<endl;
					break;
				}
			}
			if(flag == 1)
				r->left = temp;
			else if(flag == 2)
				r->right = temp;
		}

	}
	void traversal(int choice){
		if(root == NULL){
			cout<<"empty tree";
			return;
		}
		if(choice == 1)
			inorder_recursive(root);
		if(choice == 2)
			rev_inorder_recursive(root);
	}
	void inorder_recursive(Node *rt){
		int i=1;
		if(rt != NULL){
			inorder_recursive(rt->left);
			cout<<i<<" : "<<rt->keyword << " : "<<rt->meaning<<endl;
			i++;
			inorder_recursive(rt->right);
		}
	}
	void rev_inorder_recursive(Node *rt){
		int i=1;
		if(rt != NULL){
			rev_inorder_recursive(rt->right);
			cout<<i<<" : "<<rt->keyword << " : "<<rt->meaning<<endl;
			i++;
			rev_inorder_recursive(rt->left);
		}
	}
	void update(){
		string keyword, meaning;
		cout<<"enter keyword to search: ";
		cin>>keyword;
		cout<<"enter new meaning : ";
		cin>>meaning;
		q = root;
		if(root == NULL){
			cout<<"\n~empty tree";
			return;
		}
		else{
			while(q != NULL){
				int comparison = q->keyword.compare(keyword);
				if(comparison > 0){
					q = q-> left;
				}
				else if(comparison < 0){
					q = q-> right;
				}
				else if (comparison == 0){
					q->meaning = meaning;
					cout<<"\nKeyword found";
					break;
				}
			}
			cout<<"\nkeyword not found";
		}
	}
	int max_comparisons(){
		string keyword;
		cout<<"enter keyword to search: ";
		cin>>keyword;
		q = root;
		int i = 0;
		if(root == NULL){
			cout<<"\n~empty tree";
			return 0;
		}
		else{
			while(q != NULL){
				int comparison = q->keyword.compare(keyword);
				i++;
				if(comparison > 0){
					q = q-> left;
				}
				else if(comparison < 0){
					q = q-> right;
				}
				else if (comparison == 0){
					return i;
				}
			}
			cout<<"\nKeyword not found";
			return i;
		}
	}
};
int main(){
	Tree obj1,obj2;
	Tree *obj = &obj1;
	int cont = 1;
	int choice;
	cout<<"\n1 : ADD NODE ";
	cout<<"\n2 : ASCENDING ORDER";
	cout<<"\n3 : DESCENDING ORDER";
	cout<<"\n4 : UPDATE MEANING";
	cout<<"\n5 : MAX COMPARISONS TO FIND A KEYWORD";
	cout<<"\n6 : ASSIGN TO ANOTHER TREE";
	cout<<"\n7 : FIND AND DELETE A PARTICULAR KEYWORD/NODE";
	cout<<"\n99 : END"<<endl;
	while(cont){
		cout<<"--- enter choice :  ";
		cin>>choice;
		switch(choice){
			case 1:
				obj->add();
				break;
			case 2:
				obj->traversal(1);
				break;
			case 3:
				obj->traversal(2);
				break;
			case 4:
				obj->update();
				break;
			case 5:
				cout<<"max comparisons"<<obj->max_comparisons()<<endl;
				break;
			case 6:
				break;
			case 7:
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

