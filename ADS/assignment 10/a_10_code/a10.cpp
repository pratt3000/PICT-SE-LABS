#include<bits/stdc++.h>
#include"FileHandler.cpp"
using namespace std;

void index(){
	cout<<"\n----------------------------------------------------------------------";
	cout<<"\n\tOPTION INDEX: ";
	cout<<"\nPress 1: List Student Profiles in DataBase";
	cout<<"\nPress 2: Search Student Profile";
	cout<<"\nPress 3: Add New Student Profile";
	cout<<"\nPress 4: Update Existing Student Profile";
	cout<<"\nPress 5: Delete Student Profile";
	cout<<"\nPress 6: Clear Database!";
	cout<<"\n----------------------------------------------------------------------\n";
}

int main(){
	FileHandler file("student.dat");
	int choice,rollNo;
	char ch='N';
	bool flag;
	
	index();
	cout<<"\nEnter Choice [0-Exit|99-Index]: ";
	cin>>choice;
	
	while(choice){
		switch(choice){
			case 1 :	file.listProfiles();
						break;
						
			case 2 :	cout<<"\nEnter Roll No to Search: ",cin>>rollNo;
						flag=file.searchProfile(rollNo);
						if(flag==false)
							cout<<"\nRecord Not Found!\n";
						break;
					
			case 3 :	flag=file.addProfile();
						if(flag==false)
							cout<<"\nRecord Exists, Try Update!\n";
						else
							cout<<"\nProfile added Successfully!\n";
						break;
				
			case 4 :	cout<<"\nEnter Roll No to Update: ",cin>>rollNo;
						flag=file.editProfile(rollNo);
						if(flag==false)
							cout<<"\nRecord Not Found!\n";
						else
							cout<<"\nProfile Updated Successfully!\n";
						break;
						
			case 5 :	cout<<"\nEnter Roll No to Delete: ",cin>>rollNo;
						flag=file.deleteProfile(rollNo);
						if(flag==false)
							cout<<"\nRecord Not Found!\n";
						else
							cout<<"\nProfile Deleted Successfully!\n";
						break;
			
			case 6 : 	cout<<"\nThis Operation will Erase DataBase!";
						cout<<"\nPress:(Y) to Proceed: ",cin>>ch;
						if(ch=='Y' or ch=='y'){
							file.clear();
							cout<<"\nDatabase Cleared!\n";
						}
						else
							cout<<"\nAborted by User!\n";
						break;
			
			case 99:	index();
						break;
			
			default:	cout<<"Enter Valid Choice from Index!";
						index();						
		}
		cout<<"\nEnter Choice [0-Exit|99-Index]: ";
		cin>>choice;
	}
	cout<<"\nEND!\n";
	return 0;
}
