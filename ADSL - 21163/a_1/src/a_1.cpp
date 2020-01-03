//============================================================================
// Name        : a_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
class Node {
	Node* left, * right;
	int value;
public:
	Node(int val) {
		left = NULL;
		right = NULL;
		value = val;
	}
	friend class Tree;
};
template <typename T>
class Stack1 {
	T data[100];
	int top1;
public:
	Stack1() {
		top1 = 0;
		for (int i = 0; i < 100; i++)
			data[i] = 0;
	}
	T top() {
		return data[top1];
	}
	void push(T var) {
		top1++;
		data[top1] = var;
	}
	void pop() {
		data[top1] = 0;
		top1--;
	}
	bool isEmpty() {
		if (top1 == 0 && data[top1] == 0) {
			return 1;
		}
		return 0;
	}
};
template <typename T>
class Queue1 {
	T data[100];
	int front, back;
public:
	Queue1() {
		front = 50;
		back = 50;
		for (int i = 0; i < 100; i++)
			data[i] = 0;
	}
	void enqueue(T val) {
		data[back] = val;
		back--;
	}
	T dequeue() {
		front--;
		return data[front + 1];
	}
	bool isEmpty() {
		if (data[back] == 0 && front == back)
			return 1;
		return 0;
	}
};
class Tree {
	Node* q, * root;
public:
	friend class node;
	Tree() {
		q = NULL;
		root = NULL;
	}
	void mirror(Node* root) {
		if (root) {
			mirror(root->left);
			mirror(root->right);
			swap(root->right, root->left);
		}
	}
	void mirrorInitialize() {
		mirror(root);
	}
	void traversal(int choice) {
		if (root == NULL) {
			cout << "empty tree";
			return;
		}
		if (choice == 0)
			inorder_recursive(root);
		if (choice == 1)
			preorder_recursive(root);
		if (choice == 2)
			postorder_recursive(root);
	}
	void add() {
		int val;
		bool side;
		if (root == NULL) {
			cout << "enter node value";
			cin >> val;
			root = new Node(val);
			goto set;
		}
		else {
		set:
			cout << "\nenter node value";
			cin >> val;
			if (val == 100) {
				return;
			}
			q = root;
			while (1) {
				cout << "L/R node?(0/1) : ";
				cin >> side;
				if (side == 1) {
					if (q->right != NULL)
						q = q->right;
					else {
						cout << "NULL node found/";
						q->right = new Node(val);
						goto set;
					}
				}
				else if (side == 0) {
					if (q->left != NULL)
						q = q->left;
					else {
						cout << "NULL node found/";
						q->left = new Node(val);
						goto set;
					}
				}
			}
		}
	}
	void inorder_recursive(Node* rt) {
		if (rt != NULL) {
			inorder_recursive(rt->left);
			cout << rt->value << " ";
			inorder_recursive(rt->right);
		}
	}
	void preorder_recursive(Node* rt) {
		if (rt != NULL) {
			cout << rt->value << " ";
			preorder_recursive(rt->left);
			preorder_recursive(rt->right);
		}
	}
	void postorder_recursive(Node* rt) {
		if (rt != NULL) {
			postorder_recursive(rt->left);
			postorder_recursive(rt->right);
			cout << rt->value << " ";
		}
	}
	void inorder() {
		Stack1 <Node*> st;
		q = root;
		int flag = 0;
		while (flag == 0) {
			if (q != NULL) {
				st.push(q);
				q = q->left;
			}
			else if (!st.isEmpty()) {
				q = st.top();
				st.pop();
				cout << q->value << " ";
				q = q->right;
			}
			else {
				flag = 1;
			}
		}
	}
	void preorder() {
		Stack1 <Node*> st;
		q = root;
		int flag = 0;
		while (flag == 0) {
			if (q != NULL) {
				cout << q->value << " ";
				st.push(q);
				q = q->left;
			}
			else if (!st.isEmpty()) {
				q = st.top();
				st.pop();
				q = q->right;
			}
			else {
				flag = 1;
			}
		}
	}
	void postorder() {
		if (root == NULL) {
			cout << "\nTree is Empty!";
			return;
		}
		cout << "\n";
		Stack1 <Node*> stack1, stack2;
		Node* p = root;
		stack1.push(p);
		while (!stack1.isEmpty()) {
			p = stack1.top();
			stack1.pop();
			stack2.push(p);
			if (p->left != NULL)
				stack1.push(p->left);
			if (p->right != NULL)
				stack1.push(p->right);
		}
		while (!stack2.isEmpty()) {
			p = stack2.top();
			stack2.pop();
			cout << p->value << " ";
		}
	}
	void eraseTree(Node* rt) {
		if (rt != NULL) {
			eraseTree(rt->left);
			eraseTree(rt->right);
			rt->left = NULL;
			rt->right = NULL;
			delete(rt);
		}
	}
	void initializeEraseTree() {
		eraseTree(root);
		root = NULL;
	}
	void assignTreeInitialize() {
		Tree obnew;
		obnew.root->value = root->value;
		treeInitialize(root, obnew.root);
	}
	void treeInitialize(Node* rt, Node* rt1) {
		if (rt != NULL) {
			rt1->left = rt->left;
			rt1->right = rt->right;
			treeInitialize(rt->left, rt1->left);
			treeInitialize(rt->right, rt1->right);
		}
		cout << "\nCHECK : \n";
		inorder_recursive(rt);
		cout << endl;
		inorder_recursive(rt1);
	}
	bool checkEqual(Node* root1, Node* root) {
		int eq = 1;
		if (root1 != root) {
			eq = 0;
		}
		if (root != NULL) {
			if (root1 != root) {
				eq = 0;
			}
			checkEqual(root1->left, root->left);
			checkEqual(root1->right, root->right);
		}
		return eq;
	}
	void checkEqualinitialize(Tree obj1) {
		if (checkEqual(obj1.root, root)) {
			cout << "\nEQUAL TREES";
		}
		else {
			cout << "\nnot equal";
		}
	}
	void printNodesLevelWise_noRoot() {
		q = root;
		queue <Node*> qu;
		if (q == NULL)
			cout << "\nEmpty tree";
		else {
			do {
				if(q->left != NULL)
					qu.push(q->left);
				if(q->right != NULL)
					qu.push(q->right);
				cout << q->value;
				q = qu.front();
				qu.pop();
			} while (!qu.empty());
		}
	}
};
int main() {
	Tree obj1, obj2;
	Tree* obj = &obj1;
	int cont = 1;
	int val;
	int select;
	int choice;
	cout << "\n01:ADD NODE ";				
	cout << "\n02:IN-ORDER";				
	cout << "\n03:PRE-ORDER";				
	cout << "\n04:POST-ORDER";		
	cout << "\n05:MIRROR TREE";			
	cout << "\n06:ERASE TREE";			
	cout << "\n07:ASSIGN TO ANOTHER TREE";// error
	cout << "\n08:CHECK IF EQUAL";		
	cout << "\n09:PRINT LEVEL WISE";	//error
	cout << "\n10:SWITCH TREES";
	cout << "\n99:END";
	while (cont) {
		cout << "\n--- enter choice :  ";
		cin >> choice;
		switch (choice) {
		case 1:
			obj->add();
			break;
		case 2:
			obj->traversal(0);
			cout << endl;
			obj->inorder();
			break;
		case 3:
			obj->traversal(1);
			cout << endl;
			obj->preorder();
			break;
		case 4:
			obj->traversal(2);
			//cout << endl;
			obj->postorder();		
			break;
		case 5:
			obj->mirrorInitialize();
			break;
		case 6:
			obj->initializeEraseTree();
			break;
		case 7:
			obj->assignTreeInitialize();
			break;
		case 8:
			if (select)
				obj->checkEqualinitialize(obj2);
			else
				obj->checkEqualinitialize(obj1);
			break;
		case 9:
			obj->printNodesLevelWise_noRoot();
			break;
		case 10:
			cout << "tree1 or tree2?(0/1)";
			cin >> select;
			if (select)
				obj = &obj2;
			else
				obj = &obj1;
			break;
		case 99:
			cont = 0;
			break;
		default:break;
		}
	}
	cout << "\n~ TERMINATED";
	return 0;
}

