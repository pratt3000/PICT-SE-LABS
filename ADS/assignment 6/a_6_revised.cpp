//============================================================================
// Name        : a06.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define MAX 29

class Dictionary{
	string word;
	string meaning;
public:
	Dictionary();
	Dictionary(string,string);
	void print();
	void read();
	friend class Hash;
};
Dictionary::Dictionary(){
	this->word[0]='\0';
	this->meaning[0]='\0';
}
Dictionary::Dictionary(string word,string meaning){
	this->word=word;
	this->meaning=meaning;
}
void Dictionary::print(){
	cout<<"\n"<<word<<": "<<meaning;
}
void Dictionary::read(){
	cout<<"\nEnter Word: ";
	cin>>word;
	cout<<"\nEnter Meaning: ";
	cin.ignore();
	getline(cin,meaning);
}




class Hash{
	Dictionary table[MAX];
public:;
	int hashFunction(Dictionary);
	bool insertWithReplacement(Dictionary);
	bool insertWithoutReplacement(Dictionary);
	void printTable();
	void showMeaning(int);
	int searchEntry(string);
	bool deleteEntry(string);
	void menu();
};
int Hash::hashFunction(Dictionary entry){
	int location=0;
	for(unsigned int i=0; i < entry.word.length(); i++){
		location=location+entry.word[i];
	}
	location=location%MAX;
	return location;
}
bool Hash::insertWithoutReplacement(Dictionary entry){
	int index=hashFunction(entry);
	int count=0;
	if(!table[index].word.length()){
		table[index]=entry;
		cout<<"\nInserted!";
		return true;
	}
	for(int i=index;;i++){
		if(i==MAX)	i=0;
		if(!table[i].word.length()){
			table[i]=entry;
			cout<<"\nInserted!";
			return true;
		}
		count++;
		if(count>=MAX)	break;
	}
	cout<<"\nTable Full!";
	return false;
}
bool Hash::insertWithReplacement(Dictionary entry){
	int index=hashFunction(entry);
	if(!table[index].word.length()){
		table[index]=entry;
		cout<<"\nInserted!";
		return true;
	}
	Dictionary current=table[index];
	if(index==hashFunction(current))
		return insertWithoutReplacement(entry);

	table[index]=entry;
	if(insertWithoutReplacement(current)==false){
		table[index]=current;
		return false;
	}
	return true;
}
int Hash::searchEntry(string key){
	Dictionary entry(key," ");
	int count=0;
	int index=hashFunction(entry);
	for(int i=index; count<MAX;count++,i++){
		if(i==MAX)
			i=0;

		if(table[i].word==key){
			cout<<"\nNo. of Comparisons: "<<count+1;
			return i;
		}
	}
	cout<<"\nNo. of Comparisons: "<<count;
	return -1;
}

void Hash::printTable(){
	cout<<"\nindex\tword\tmeaning";
	for(int i=0;i<MAX;i++){
		cout<<"\n"<<i<<"\t"<<table[i].word<<"\t"<<table[i].meaning;
	}
}
bool Hash::deleteEntry(string key){
	int index=searchEntry(key);
	if (index==-1)
		return false;
	Dictionary blank;
	table[index]=blank;
	return true;
}
void Hash::showMeaning(int index){
	cout<<"\n"<<table[index].word<<": "<<table[index].meaning;
}
void Hash::menu(){
	cout<<"\n------------------------------------------------------";
	cout<<"\n           OPTION INDEX";
	cout<<"\nPress 1  : Add Word into Dictionary";
	cout<<"\nPress 2  : Search Word";
	cout<<"\nPress 3  : Delete Word";
	cout<<"\nPress 4  : Print Hash table";
	cout<<"\nPress 99 : Display Option Index";
	cout<<"\n------------------------------------------------------";
}
int main() {
	int replacement=0;
	while(replacement!=1 and replacement!=2){
		cout<<"\nChoose Insertion Method.";
		cout<<"\n1. With Replacement";
		cout<<"\n2. Without Replacement";
		cout<<"\nEnter Choice: ";
		cin>>replacement;
	}
	if (replacement==2)
		replacement=0;

	int choice;
	Hash obj;
	Dictionary entry;
	string key;
	int index;
	bool flag;

	obj.menu();
	cout<<"\n\nEnter Choice: ";
	cin>>choice;

	while(choice){
		switch(choice){
		case 1:	entry.read();
				if(replacement)
					obj.insertWithReplacement(entry);
				else
					obj.insertWithoutReplacement(entry);
				break;

		case 2:	cout<<"\nEnter Word to Search: ";
				cin>>key;
				index=obj.searchEntry(key);
				if(index!=-1){
					cout<<"\n"<<key<<" found at index: "<<index;
					obj.showMeaning(index);
				}
				else
					cout<<"\n"<<key<<" not Found!";
				break;

		case 3:	cout<<"\nEnter Word to Search: ";
				cin>>key;
				flag=obj.deleteEntry(key);
				if(flag==true)
					cout<<"\n"<<key<<" Deleted Successfully!";
				else
					cout<<"\n"<<key<<" not Found!";
				break;

		case 4:	obj.printTable();
				break;

		case 99: obj.menu();
					break;

		default:cout<<"\nInvalid Choice! Please, Try Again.";
		}
		cout<<"\n\nEnter Choice: ";
		cin>>choice;
	}
	cout<<"\nEND...";
	return 0;
}
