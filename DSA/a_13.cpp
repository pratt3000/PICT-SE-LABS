#include<bits/stdc++.h>
using namespace std;
#define MAX 50
class Database{
	float array[MAX];
	int n;
public:
	Database();
	void setData(int);
	void display();
	void quickSort(int,int);
	void topFive();
	void menu();
};
void Database::quickSort(int low,int high){
	if(low<high){
		int pivot=low;
		int i=low;
		int j=high;
		float temp;
		while(i<j){
			while(array[i] <= array[pivot] && i<j )
		 		i++;
			while(array[j]>array[pivot] && i<=j )
				j--;
			if(i<j){
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}	
		}
		temp=array[pivot];
		array[pivot]=array[j];
		array[j]=temp;
		quickSort(low,j-1);
		quickSort(j+1,high);
	}
}
Database::Database(){
	for(int i=0;i<MAX;i++)
		array[i]=0;
	n=0;
}
void Database::topFive(){
	quickSort(0,n-1);
	int j=n-1,count=0;
	cout<<"\nTop Five Scores: ";
	while(j>=0&&count<5){
		cout<<array[j]<<" ";
		count++;
		while(array[j]==array[j-1])
			j--;
		j--;
	}
}
void Database::setData(int no){
	n=no;
	for(int i=0;i<n;i++){
label:
		cout<<"\nEnter Marks for Roll No. "<<i+1<<": ";
		cin>>array[i];
		if(array[i]<0||array[i]>100){
			cout<<"\nError: Invalid Value for Percentage!\nTry Again!\n";
			goto label;
		}
	}
}
void Database::display(){
	cout<<"\nArray of Marks: \n";
	for(int i=0;i<n;i++)
		cout<<array[i]<<"\n";
}
void Database::menu(){
	cout<<"\n-----------------DEQUE OPERATIONS-------------------";
	cout<<"\nPress 1: Enter Score Array";
	cout<<"\nPress 2: Sort Scores by Quick Sort";
	cout<<"\nPress 3: Display Top Five Scores";
	cout<<"\nPress 4: Display Score Array";	
	cout<<"\nPress 9: Display Operations";
}
int main(){
	Database result;
	int choice,key,n;
	result.menu();
	do{
		cout<<endl<<"____________________________________________________";
		cout<<endl<<"Enter Choice [Press 0:exit|9:Options]: ";
		cin>>choice;
		switch(choice){
			case 1: cout<<"\nEnter No. of Students: ";cin>>n;
					result.setData(n);
					break;
			case 2: cout<<"\nSorted by Quick Sort!";
					result.quickSort(0,n-1);
					break;
			case 3: result.topFive();
					break;
			case 4: result.display();
					break;
			case 9: result.menu();
					break;
			case 0: cout<<"\n----------------------END---------------------------\n";
					break;
			default: cout<<"\nInvalid Choice Entered!";
		}
	}while(choice);	
	return 0;
}