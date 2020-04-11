//============================================================================
// Name        : a_9.cpp
// Author      : Prathamesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Node {
public:
	Node* next;
	int value;
	int visited;
	Node(int value) {
		next = NULL;
		this->value = value;
		visited = 0;
	}
	friend class List;
};
class List {
	Node* start, *startTemp;
public:
	List() {
		start = NULL;
		startTemp = NULL;
	}
	//choice == 1 for ret count and choice == 0 for adding node
	int add_or_countNode(int value, int choice) {
		Node* temp = new Node(value), * temp2 = start;
		int count = 0;
		if (start == NULL) {
			start = temp;
			return 0;
		}
		else {
			while (temp2->next != NULL) {
				temp2 = temp2->next;
				count++;
			}
			if (choice == 0)
				temp2->next = temp;
			return count;
		}
	}
	// choice == 1 for update and choice == 0 for delete
	bool del_or_updateNode(int value, int newValue, bool choice) {
		Node* temp2 = start, * prev;
		if (start == NULL)
			return 0;
		else if (start->value == value) {
			start = start->next;
			return 1;
		}
		else {
			while (temp2 != NULL) {
				prev = temp2;
				temp2 = temp2->next;
				if (temp2->value == value) {
					if (choice == 0)
						prev->next = temp2->next;
					else if (choice == 1)
						temp2->value = newValue;
					return 1;
				}
			}
			cout << "\n--- NOT FOUND ---";
			return 0;
		}
	}
	void cleanVisited(List ob2) {
		Node* temp1 = start;
		Node* temp2 = ob2.start;
		while (temp1 != NULL) {
			temp1->visited = 0;
			temp1 = temp1->next;
		}
		while (temp2 != NULL) {
			temp2->visited = 0;
			temp2 = temp2->next;
		}
	}
	void intersection(List ob2) {
		Node* temp1 = start;
		Node* temp2 = ob2.start;
		while (temp1 != NULL) {
			while (temp2 != NULL) {
				if ((temp1->value == temp2->value) && (temp1->visited == 0) && (temp2->visited == 0)) {
					temp2->visited == 1;
					temp1->visited == 1;
					cout << temp1->value << endl;
				}
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
			temp2 = ob2.start;
		}
	}
	void union1(List ob2) {
		intersection(ob2);
		Node* temp1 = start;
		Node* temp2 = ob2.start;
		while (temp1 != NULL) {
			if (temp1->visited == 0)
				cout << temp1->value << endl;
			temp1 = temp1->next;
		}
		while (temp2 != NULL) {
			if (temp2->visited == 0)
				cout << temp2->value << endl;
			temp2 = temp2->next;
		}
	}
	void subtraction(List ob2) {
		cleanVisited(ob2);
		Node *temp2 = ob2.start, *temp1 = start, *temp = startTemp;
		while (temp1 != NULL) {
			while (temp2 != NULL) {
				if ((temp1->value == temp2->value) && (temp1->visited == 0) && (temp2->visited == 0)) {
					temp2->visited == 1;
					temp1->visited == 1;
					if(temp!= NULL) {
						while (temp->next != NULL) {
							temp = temp->next;
						}
					}
					temp->next->value = temp1->value;  //////////////exception is thrown here
				}
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
			temp2 = ob2.start;
		}
		
		//till here intersection is found and new list is created of the same
		//now the intersection is removed from first set
		//same algo as intersection for this
		
		cleanVisited(ob2);
		temp2 = temp;
		while (temp1 != NULL) {
			while (temp2 != NULL) {
				if ((temp1->value != temp2->value) && (temp1->visited == 0) && (temp2->visited == 0)) {
					temp2->visited == 1;
					temp1->visited == 1;
					cout << temp1->value << endl;
				}
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
			temp2 = temp;
		}
	}
};
class Set {
	List ob1, ob2;
public:
	//choice == 0 to add in ob1 and choice == 1 to add in ob2
	void addInSet(bool choice) {
		cout << "\nVALUE : ";
		int value;
		cin >> value;
		if (choice == 0)
			ob1.add_or_countNode(value, 0);
		else
			ob2.add_or_countNode(value, 0);
	}
	//choice == 0 to delete from ob1 and choice == 1 to delete from ob2
	void delteFromSet(bool choice) {
		cout << "\nVALUE : ";
		int value;
		cin >> value;
		if (choice == 0)
			ob1.del_or_updateNode(value, -1, 0);
		else if (choice == 1)
			ob2.del_or_updateNode(value, -1, 0);
	}
	void countInSet(bool choice) {
		int count;
		if (choice == 0)
			count = ob1.add_or_countNode(-1, 1);
		else
			count = ob2.add_or_countNode(-1, 1);
		cout << "\nSet count = " << count + 1 << endl;
	}
	void updateInSet(bool choice) {
		int search, update;
		cout << "\nTo search : ";
		cin >> search;
		cout << "To update with : ";
		cin >> update;
		if (choice == 0)
			ob1.del_or_updateNode(search, update, 1);
		else if (choice == 1)
			ob2.del_or_updateNode(search, update, 1);
	}
	void findIntersection() {
		ob1.intersection(ob2);
		ob1.cleanVisited(ob2);
	}
	void findUnion() {
		ob1.union1(ob2);
		ob1.cleanVisited(ob2);
	}
	void diff(bool choice) {
		if(choice == 0)
			ob1.subtraction(ob2);
		else
			ob2.subtraction(ob1);
	}
};
int main() {
	Set ob;
	int cont = 1;
	int choice;
	cout << "\n01 : ADD IN SET A\t\t";
	cout << "02 : ADD IN SET B";
	cout << "\n03 : DELETE FROM SET A\t\t";
	cout << "04 : DELETE FROM SET B";
	cout << "\n05 : UPDATE VALUE OF SET A\t";
	cout << "06 : UPDATE VALUE OF SET B";
	cout << "\n07 : COUNT OF SET A\t\t";
	cout << "08 : COUNT OF SET B";
	cout << "\n09 : FIND INTERSECTION\t\t";
	cout << "10 : FIND UNION";
	cout << "\n11 : A - B\t\t\t";
	cout << "12 : B - A";
	cout << "\n99 : END" << endl;
	while (cont) {
		cout << "--- Enter Choice : ";
		cin >> choice;
		switch (choice) {
		case 1:ob.addInSet(0);
			break;
		case 2:ob.addInSet(1);
			break;
		case 3:ob.delteFromSet(0);
			break;
		case 4:ob.delteFromSet(1);
			break;
		case 5:ob.updateInSet(0);
			break;
		case 6:ob.updateInSet(1);
			break;
		case 7:ob.countInSet(0);
			break;
		case 8:ob.countInSet(1);
			break;
		case 9:ob.findIntersection();
			break;
		case 10:ob.findUnion();
			break;
		case 11:ob.diff(0);
			break;
		case 12:ob.diff(1);
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
/*A-B throws an exception*/
