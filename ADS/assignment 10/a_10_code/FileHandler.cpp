#include<iostream>
#include<fstream>
#include"student.cpp"
using namespace std;

#define active profile.deleted==false

class FileHandler{
private:	
	string fileName;
	int cursor;
public:
	FileHandler(string);
	~FileHandler();
	bool addProfile();
	void print_debug();
	void listProfiles();
	void clear();
	bool searchProfile(int);
	bool deleteProfile(int);
	bool editProfile(int);
};

FileHandler::FileHandler(string fileName){
	this->fileName=fileName;

	ofstream fileDesc;
	fileDesc.open(fileName,ios::out|ios::app);
	fileDesc.close();
}

bool FileHandler::searchProfile(int rollNo){
	Student profile;
	ifstream fileDesc;
	
	fileDesc.open(fileName,ios::in);
	
	fileDesc.read((char*)&profile,sizeof(profile));
	while(fileDesc.eof()==false){
		if(profile.rollNo==rollNo and active){
			fileDesc.close();
			profile.display();
			return true;
		}
		fileDesc.read((char*)&profile,sizeof(profile));
	}
	fileDesc.close();
	return false;
}

void FileHandler::clear(){
	ofstream fileDesc;
	fileDesc.open(fileName,ios::out);
	fileDesc.close();
}

void FileHandler::print_debug(){
	Student profile;
	ifstream fileDesc;
	bool flag;
	
	fileDesc.open(fileName,ios::in);
	
	fileDesc.read((char*)&profile,sizeof(profile));
	while(fileDesc.eof()==false){
			profile.display();
			if(not active)
				cout<<"#Inactive!\n";
			fileDesc.read((char*)&profile,sizeof(profile));
	}
	fileDesc.close();
	return;
}

void FileHandler::listProfiles(){
	Student profile;
	ifstream fileDesc;
	bool flag;
	
	fileDesc.open(fileName,ios::in);
	
	cout<<"\nROLL NO:\n-----------";
	
	fileDesc.read((char*)&profile,sizeof(profile));
	while(fileDesc.eof()==false){
			if(active)
				cout<<"\n"<<profile.rollNo;
			fileDesc.read((char*)&profile,sizeof(profile));
	}
	fileDesc.close();
	return;
}

bool FileHandler::addProfile(){
	Student profile;
	ofstream fileDesc;
	
	profile.getData();
	if(searchProfile(profile.rollNo)==true)
		return false;
	
	fileDesc.open(fileName,ios::out|ios::app);
	fileDesc.write((char*)&profile,sizeof(profile));
	fileDesc.close();
	return true;
}

bool FileHandler::deleteProfile(int rollNo){
	Student profile;
	fstream fileDesc;
	fileDesc.open(fileName,ios::in|ios::out);
	
	cursor=fileDesc.tellg();
	fileDesc.read((char*)&profile,sizeof(profile));
	while(fileDesc.eof()==false){
		if(profile.rollNo==rollNo and active){
			profile.deleted=true;
			fileDesc.seekp(cursor);
			fileDesc.write((char*)&profile,sizeof(profile));
			fileDesc.close();
			return true;
		}
		cursor=fileDesc.tellg();
		fileDesc.read((char*)&profile,sizeof(profile));
	}
	fileDesc.close();
	return false;
}

bool FileHandler::editProfile(int rollNo){
	Student profile;
	
	char div[8];
	char address[256];
	
	fstream fileDesc;
	fileDesc.open(fileName,ios::in|ios::out);
	
	cursor=fileDesc.tellg();
	fileDesc.read((char*)&profile,sizeof(profile));
	while(fileDesc.eof()==false){
		if(profile.rollNo==rollNo and active){
			cin.ignore();
			cout<<"\nEnter Updated Division: ",cin.getline(div,8);
			cout<<"Enter Updated Address:\n",cin.getline(address,256);
			profile.setData(div,address);
			fileDesc.seekp(cursor);
			fileDesc.write((char*)&profile,sizeof(profile));
			fileDesc.close();
			return true;
		}
		cursor=fileDesc.tellg();
		fileDesc.read((char*)&profile,sizeof(profile));
	}
	fileDesc.close();
	return false;
}

FileHandler::~FileHandler(){
	Student profile;
	ifstream fileDesc1;
	ofstream fileDesc2;
		
	fileDesc1.open(fileName,ios::in);
	fileDesc2.open("temp.dat",ios::out);
	
	fileDesc1.read((char*)&profile,sizeof(profile));
	while(fileDesc1.eof()==false){
		if(active)
			fileDesc2.write((char*)&profile,sizeof(profile));
			
		fileDesc1.read((char*)&profile,sizeof(profile));
	}
	fileDesc1.close();
	fileDesc2.close();
	remove(fileName.c_str());
	rename("temp.dat",fileName.c_str());
}
