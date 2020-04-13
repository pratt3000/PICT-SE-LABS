#include<iostream>
using namespace std;
#include"sets.h"

template<typename T>
SetNode<T>::SetNode(){
	link = NULL;
}

template<typename T>
SetNode<T>::SetNode(T data){
	this->data=data;
	link=NULL;
}

template<typename T>
Set<T>::Set(){
	start=NULL;
}

template<typename T>
void Set<T>::print(){
	if(start == NULL){
		cout<<"{ # }";
		return;
	}
	SetNode<T> *p = NULL;
	cout<<"{ ";
	for(p=start; p!=NULL; p=p->link)
		cout<<p->data<<", ";
	cout<<"\b\b }";
	return;
}

template<typename T>
bool Set<T>::contains(T data){
	SetNode<T> *p;
	for(p=start; p!=NULL; p=p->link){
		if(p->data==data)
			return true;
	}
	return false;
}

template<typename T>
void Set<T>::add(T data){
	if(contains(data)==true)
		return;
	
	SetNode<T> *temp=new SetNode<T>(data);
	temp->link=start;
	start=temp;
	return;
}

template<typename T>
bool Set<T>::remove(T data){
	SetNode<T> *p=NULL;
	SetNode<T> *q=NULL;
	for(p=start; p!=NULL; p=p->link){
		if(p->data==data)
			break;
		q=p;
	}
	
	if(p==NULL)
		return false;
	
	if(q==NULL)
		start=start->link;
	else
		q->link=p->link;
	
	delete p;
	return true;
}

template<typename T>
int Set<T>::size(){
	SetNode<T> *p=NULL;
	int count=0;
	for(p=start; p!=NULL; p=p->link, count++);
	return count;
}

template<typename T>
bool Set<T>::isSubset(Set<T> a){
	SetNode<T> *p=NULL;
	for(p=start; p!=NULL; p=p->link){
		if(a.contains(p->data) == false)
			return false;
	}
	return true;
}

template<typename T>
Set<T> Set<T>::unification(Set<T> b){
	Set<T> c;
	SetNode<T> *p=NULL;
	
	for(p=this->start; p!=NULL; p=p->link)
		c.add(p->data);
	
	for(p=b.start; p!=NULL; p=p->link)
		c.add(p->data);
	
	return c;
}

template<typename T>
Set<T> Set<T>::intersection(Set<T> b){
	Set<T> c;
	SetNode<T> *p=NULL;
	for(p=start; p!=NULL; p=p->link){
		if(b.contains(p->data))
			c.add(p->data);
	}
	return c;
}

template<typename T>
Set<T> Set<T>::difference(Set<T> b){
	Set<T> c;
	SetNode<T> *p=NULL;
	
	for(p=this->start; p!=NULL; p=p->link)
		c.add(p->data);
	
	for(p=b.start; p!=NULL; p=p->link)
		c.remove(p->data);
		
	return c;
}











