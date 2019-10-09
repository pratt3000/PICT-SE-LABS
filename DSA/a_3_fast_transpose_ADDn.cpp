//============================================================================
// Name        : a_3_fast_transpose_ADDn.cpp
// Author      : Prathamesh
// Version     : FEDORA 20
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class matrix{
	int m,n,t;
	int mat[10][3];
	int ro,co;
	static int disp;
public:
	void read();
	void display();
	matrix add();
	matrix transpose();
};
int matrix :: disp = 1;
void matrix :: read(){
	int flag=1;
	while(flag){
		flag=0;
		cout<<"Enter number of ROWS           :";       cin>>m;  ro=m;
		cout<<"Enter number of COLUMNS        :";       cin>>n;  co=n;
		cout<<"Enter number of NON-ZERO inputs:"; 	    cin>>t;
		if(t>m*n){
			cout<<"!!!!!!!!!!!!!!!~error : out of range!!!!!!!!!!!!!!!!\n";
			cout<<"----------------------------------------------------\n";
			flag=1;
		}
	}
	cout<<"----------------------------------------------------\n";
	for(int i=0;i<t;i++){
		cout<<"ENTER PARAMETER "<<i+1<<"(ascending order)"<<": ";
		cout<<"Row   =";	        			          cin>>mat[i][0];
		cout<<"	\t                   Column= ";	    	  cin>>mat[i][1];
		cout<<"\t\t                   Value = ";	  	  cin>>mat[i][2];
		cout<<"----------------------------------------------------\n";
		if(mat[i][0]>m || mat[i][1]>n ||mat[i][2]==0){
			cout<<"!!!!!!!!!!!!!!!!!~error : inputs out of scope  !!!!!!!!!!!!!!!!!!!!\n";
			cout<<"----------------------------------------------------\n";
			i--;
		}
		if(i>0){
			if(mat[i][0]<mat[i-1][0] ){
				cout<<"!!!!!!!!!!!!~error : enter in ascending order!!!!!!!!!!!!\n";
				cout<<"----------------------------------------------------\n";
				i--;
			}
		}
	}
}
void matrix :: display(){

	cout<<"SPARSE MATRIX "<<disp<< ": rows="<<ro<<"  column="<<co<<"  non zero elements="<<t<<endl;
	disp++;
	for(int i=0;i<t;i++)
		cout<<mat[i][0]<<"  "<<mat[i][1]<<"  "<<mat[i][2]<<"\n";
	cout<<"----------------------------------------------------\n";
}
matrix matrix :: add(){
	matrix ob1,ob2;
	int flag=1;
	while(flag){
		ob1.read();
		if(m==ob1.m && n==ob1.n){
			flag=0;
		}
		else{
			cout<<"\nRE-ENTER MAXTRIX WITH CORRECT DIMENSIONS:";
		}
	}
	ob1.display();
	int i,j,k;
	for(i=0,j=0,k=0; i<t || j<ob1.t ;k++){
		if(mat[i][0]>ob1.mat[j][0]){
			ob2.mat[k][0]=ob1.mat[j][0];
			ob2.mat[k][1]=ob1.mat[j][1];
			ob2.mat[k][2]=ob1.mat[j][2];
			j++;
		}
		else if(mat[i][0]<ob1.mat[j][0]){
			ob2.mat[k][0]=mat[i][0];
			ob2.mat[k][1]=mat[i][1];
			ob2.mat[k][2]=mat[i][2];
			i++;
		}
		else{
			if(mat[i][1]>ob1.mat[j][1]){
				ob2.mat[k][0]=ob1.mat[j][0];
				ob2.mat[k][1]=ob1.mat[j][1];
				ob2.mat[k][2]=ob1.mat[j][2];
				j++;
				}
			else if(mat[i][1]<ob1.mat[j][1]){
				ob2.mat[k][0]=mat[i][0];
				ob2.mat[k][1]=mat[i][1];
				ob2.mat[k][2]=mat[i][2];
				i++;
				}
			else{
				int temp;
				temp = mat[i][2] + ob1.mat[j][2];
				if(temp!=0){
					ob2.mat[k][0]=mat[i][0];
					ob2.mat[k][1]=mat[i][1];
					ob2.mat[k][2]=temp;i++;j++;
					}
				}
			}

		}
	ob2.t=k;
	return ob2;
}
matrix matrix :: transpose(){
		matrix ob2;
		ob2.m=n;
		ob2.n=m;
		ob2.t=t;
		int rsize[t];
		int rstart[t];
		int i,k;
		for(i=0;i<t;i++)
		{
			rsize[i]=0;
			rstart[i]=0;
		}
		for(i=0;i<t;i++)
		{
			rsize[(mat[i][1])]++;
		}
		for(i=1;i<n;i++)
		{
			rstart[i]=rstart[i-1]+rsize[i-1];
		}
		for(i=0;i<t;i++)
		{
			k=rstart[mat[i][1]];
			ob2.mat[k][0]=mat[i][1];
			ob2.mat[k][1]=mat[i][0];
		    ob2.mat[k][2]=mat[i][2];
		    rstart[k]++;
		}
		return ob2;
}

int main() {
	int e=1;
	matrix ob;
	ob.read();
	ob.display();
	while(e==1){
	cout<<"1:ADDITION\n2:TRANSPOSE\n CHOICE : ";
	int x;
	cin>>x;
	switch (x){
		case 1: ob.add().display();
				break;
		case 2: ob.transpose().display();
				break;
		default:break;
		}
	cout<<"CONTINUE?(1/0):\n ";
	cin>>e;
	}
	cout<<"~terminated";
	return 0;
}
