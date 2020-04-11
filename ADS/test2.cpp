//============================================================================
// Name        : test.cpp
// Author      : prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
class Node{
public:
	Node *left, *right;
	string keyword, meaning;

	Node(string keyword, string meaning){
		left = NULL;
		right = NULL;
		this->keyword = keyword;
		this->meaning = meaning;
	}
	friend class Tree;
};
class BST{
	Node *q, *root;
public:
	BST(){
		q = NULL;
		root = NULL;
	}
	void addInitialize(){
		int cont;
		do{
			Node* temp;
			string key, m;
			cout<<"\nKeyword : ";
			cin>>key;
			cout<<"\nMeaning : ";
			cin>>m;
			temp = new Node(key, m);
			addNode(temp);
			cout<<"\nAdd one more?(1/0)";
			cin>>cont;
		}while(cont == 1);
	}
	void addNode(Node *temp){
		Node *r;
		bool flag = 0;
		q = root;
		r = q;
		if(root == NULL){
			root = temp;
			return;
		}
		else{
			while(q != NULL){
				int comp = q->keyword.compare( temp->keyword);
				if(comp > 0){
					r = q;
					q = q-> left;
					flag = 0;
				}
				else if(comp < 0){
					r = q;
					q = q-> right;
					flag = 1;
				}
				else if (comp == 0){
					cout<<"\nAlready present"<<endl;
					break;
				}
			}
			if(flag == 0)
				r->left = temp;
			else if(flag == 1)
				r->right = temp;
		}
	}
	void treeDisplay(bool c){
		if(root == NULL){
			cout<<"\n----NO TREE----";
			return;
		}
		else if(c == 0){
			cout<<"\n----ASCENDING----"<<endl;
			ascending(root);
		}
		else if(c == 1){
			cout<<"\n----DESCENDING----"<<endl;
			descending(root);
		}
	}
	void ascending(Node *root){
		if(root != NULL){
			ascending(root->left);
			cout<<"  "<<root->keyword << "  "<<root->meaning<<endl;
			ascending(root->right );
		}
	}
	void descending(Node *root){
			if(root != NULL){
				ascending(root->right);
				cout<<"  "<<root->keyword << "  "<<root->meaning<<endl;
				ascending(root->left);
			}
		}
	void operator+ (BST obj3){
		root = copyingTree(obj3.root);
	}
	Node *copyingTree(Node *p){
		if(p==NULL){
			return NULL;
		}
		else{
			Node *t = new Node(p->keyword, p->meaning);
			(p->keyword =  t->keyword);
			(p->keyword =  t->keyword);
			t->left  = copyingTree(p->left);
			t->right = copyingTree(p->right);
			cout<<"coping done"<<endl;
			return t;
		}
	}
	void update(){
		string key;
		string newMeaning;
		cout<<"\nKeyword : ";
		cin>>key;
		Node *temp = findNode(root, key);
		if(temp == NULL)
			cout<<"\nKeyword not found";
		else{
			cout<<"\nEnter new meaning : ";
			cin>>newMeaning;
			temp->meaning = newMeaning;
		}
	}
	Node *findNode(Node *root, string key){
		q = root;
		if(root == NULL)
			return NULL;
		else{
			while(q != NULL){
				int comp= q->keyword.compare(key);
				if(comp > 0)
					q = q-> left;
				else if(comp < 0)
					q = q-> right;
				else if (comp == 0)
					return q;
			}
			return NULL;
		}
	}
	void deleteInitialize(){
		cout<<"\nEnter keyword to delete : ";
		string key;
		cin>>key;
		deleteNode(root, key);
		cout<<"deleted"<<endl;
	}
	Node *deleteNode(Node *root, string key){
		if(root == NULL)
			return root;
		if(root->keyword.compare(key)>0){
			root->left = deleteNode(root->left, key);
			return root;
		}
		else if(root->keyword.compare(key)<0){
			root->right = deleteNode(root->right, key);
			return root;
		}
		if(root->left == NULL)
			return root->right;
		else if(root->right == NULL)
			return root->left;
		else{
			Node* succparent = root->right;
			Node* succ = root->right;
			while(succ->left != NULL){
				succparent = succ;
				succ= succ->left;
			}
			succparent->left = succ->right;
			root->keyword = succ->keyword;
			delete succ;
			return root;
		}
	}
	void max_comparisons(){
		string keyword;
		cout<<"\nKeyword: ";
		cin>>keyword;
		q = root;
		int i = 0;
		if(root == NULL)
			cout<<"\nEmpty tree";
		else{
			while(q != NULL){
				int comparison = q->keyword.compare(keyword);
				i++;
				if(comparison > 0)
					q = q-> left;
				else if(comparison < 0)
					q = q-> right;
				else if (comparison == 0){
					cout<<"\nKeyword found";
					cout<<"\nComparisons required = "<<i;
				}
			}
			cout<<"\nKeyword not found";
		}
	}
};
int main() {
	BST object,copying;
	int cont;
	do{
		int choice;
		cout<<"\n1 : Add ";
		cout<<"\n2 : Ascending order";
		cout<<"\n3 : Descending order";
		cout<<"\n4 : Copy";
		cout<<"\n5 : Update";
		cout<<"\n6 : Delete";
		cout<<"\n7 : Max comparisons";
		cout<<"\n99: EXIT";
		cout<<"\nChoice : ";
		cin>>choice;
		switch(choice){
		case 1:
			object.addInitialize();
			break;
		case 2:
			object.treeDisplay(0);
			break;
		case 3:
			object.treeDisplay(1);
			break;
		case 4:
			copying = object;
			copying.treeDisplay(0);
			break;
		case 5:
			object.update();
			break;
		case 6:
			object.deleteInitialize();
			break;
		case 7:
			object.max_comparisons();
			break;
		default:
			break;
		}
		cout<<"continue?(1/0)";
		cin>>cont;
	}while(cont == 1);
	return 0;
}


