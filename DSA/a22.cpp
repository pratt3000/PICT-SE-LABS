#include <bits/stdc++.h>
using namespace std;

class str{
	char ch[200];
	public:
	str(){ ch[0]='\0'; }
	void read();
	void display();
	int substr(str);
	int subStr(str);
	int replace(str,str);
	void copy(str);
	void menu();
	int len();
	void concat(str);
	void reverse();
	int compare(str);
	int freq(char);
	int palindrome();
	str chardelete(char);
	str modify(int,int);
};
str str::modify(int start,int span){
	str s;
	int i,j=0;
	for(i=0;i<len();i++){
		if(i==start)
			i=i+span;
		else{
			s.ch[j]=ch[i];
			j++;
		}
	}
	s.ch[j]='\0';
	return s;
}
str str::chardelete(char c){
	str s;
	int i,j=0;
	for(i=0;i<len();i++){
		if(ch[i]!=c){
			s.ch[j]=ch[i];
			j++;
		}
	}
	if(i==j)
	cout<<"\t---->Character: "<<c<<" Not Found"<<endl;
	s.ch[j]='\0';
	return s;
}
int str::palindrome(){
	int i,f=1,l=len();
	for(i=0;i<len();i++)
	if(ch[i]!=ch[l-i-1])
	f=0;
	if(f)
	return 1;
	else
	return 0;
}
int str::freq(char c){
	int i,count=0;
	for(i=0;i<len();i++){
		if(ch[i]==c)
		count++;
	}
	return count;
}
int str::compare(str s1){
	int f=1,i,l,l1;
	l=len();
	l1=s1.len();
	for(i=0;i<l;i++)
	if(ch[i]!=s1.ch[i])
	f=0;
	if(l1==l&&f)
	return 1;
	else
	return 0;
}
void str::reverse(){
	int i,l=len();
	char temp;
	for(i=0;i<l/2;i++){
		temp=ch[i];
		ch[i]=ch[l-i-1];
		ch[l-i-1]=temp;
	}
	ch[l]='\0';
}
void str::menu()
{
	cout<<endl<<"------------------STRING FUNCTIONS--------------------"<<endl;
	cout<<"1  : Enter String"<<endl;
	cout<<"2  : Display"<<endl;
	cout<<"3  : Length"<<endl;
	cout<<"4  : copy"<<endl;
	cout<<"5  : concatenate"<<endl;
	cout<<"6  : find substring"<<endl;
	cout<<"7  : replace substring"<<endl;
	cout<<"8  : Reverse"<<endl;
	cout<<"9  : compare"<<endl;
	cout<<"10 : frequency of character"<<endl;
	cout<<"11 : Palindrome/not"<<endl;
	cout<<"12 : delete character"<<endl;
	cout<<"13 : delete by start and span"<<endl;
	cout<<"0  : exit"<<endl;
}
int str::len(){
	int i;
	for(i=0;ch[i]!='\0';i++);
	return i;
}
void str::copy(str s1){
	int i;
	for(i=0;s1.ch[i]!=0;i++){
		ch[i]=s1.ch[i];
	}
	ch[i]='\0';
}
void str::read(){
	cin.getline(ch,200);
}
void str::display(){
	cout<<"\t -----> "<<ch;
}
void str::concat(str s1){
	int i,j,l1,l;
	l=len();
	l1=s1.len();
	for(i=l,j=0;j<l1;j++,i++){
		ch[i]=s1.ch[j];
	}
	ch[i]='\0';
}
int str::substr(str s1){
	int l1,f,c=0,index[50],t=0;
	int i,j,l;
	l=len();

	l1=s1.len();
	for(i=0;i<=l-l1;i++){
		f=1;
		for(j=0;j<l1;j++){
			if(ch[i+j]!=s1.ch[j])
			f=0;
		}
		if(f!=0){
			c++;
			index[t]=i;
			t++;
		}
	}
	if(c>0){
		cout<<endl<<"yes at index value: ";
		for(i=0;i<t;i++){
			cout<<index[i]<<", ";
		}
		return index[0];
	}
	else{
		cout<<endl<<s1.ch<<" Not Found in "<<ch;
		return -1;
	}
}
int str::subStr(str s1){
	int l1,f,c=0,index[50],t=0;
	int i,j,l;
	l=len();
	l1=s1.len();
	for(i=0;i<=l-l1;i++){
		f=1;
		for(j=0;j<l1;j++){
			if(ch[i+j]!=s1.ch[j])
			f=0;
		}
		if(f!=0){
			c++;
			index[t]=i;
			t++;
		}
	}
	if(c>0)
		return index[0];
	else
		return -1;
}
int str::replace(str s1,str s2){
	int l1,index=0,l2;
	int i,count=0,j;
	str app;
		l1=s1.len();
		l2=s2.len();
		index=subStr(s1);
	while(index!=-1){
		//Separating the append part
		count++;
		app.ch[0]='\0';
		for(i=index+l1,j=0;i<len();i++,j++)
		{
			app.ch[j]=ch[i];
		}
		app.ch[j]='\0';
		//coping the replacement
		for(i=index,j=0;j<l2;i++,j++){
			ch[i]=s2.ch[j];
		}
		ch[i]='\0';
		concat(app);
		index=subStr(s1);
	}
	if(count)
		return 1;
	else
		return 0;
}
int main(){
	str s,s1,s2,app;
	int ch=1,i,j;
	char c,buffer[10];
	s.menu();
	cout<<endl<<"\t";
	while (ch!=0){

		switch(ch){
			case 1:cout<<"String: ";
					s.read();
					break;
			case 2: s.display();
					break;
			case 3: cout<<"-----> Length is: "<<s.len();
					break;
			case 4: cout<<"Enter String to be copied: ";
					s1.read();
					s.copy(s1);
					s.display();
					break;
			case 5: cout<<"append String: ";
					app.read();
					s.concat(app);
					s.display();
					break;
			case 6: cout<<"substring:";
					s1.read();
					s.substr(s1);
					break;
			case 7: cout<<"string to be replaced: ";
					s1.read();
					cout<<"Replacement: ";
					s2.read();
					if(s.replace(s1,s2))
					s.display();
					else
					cout<<"\t---->Not Found";
					break;
			case 8: s.reverse();
					s.display();
					break;
			case 9:cout<<"Enter St to compare: ";
					s1.read();
					if(s.compare(s1))
					cout<<"\tEqual"<<endl;
					else
					cout<<"\tNot Equal"<<endl;
					break;
			case 10:cout<<"Enter Character: ";
					cin>>c;
					s.display();
					cout<<endl;
					cout<<"\t Character freq: "<<s.freq(c);
					break;
			case 11:if(s.palindrome())
					cout<<"\t Palindrome"<<endl;
					else
					cout<<"not Palindrome"<<endl;
					break;
			case 12:cout<<"Enter char: ";
					cin>>c;
					s=s.chardelete(c);
					s.display();
					break;
			case 13:cout<<"Starting Point: ";
					cin>>i;
					cout<<"Span: ";
					cin>>j;
					s1=s.modify(i-1,j-1);
					if (s1.len())
					s1.display();
					else
					cout<<"\t---->NULL";
					break;
			case 0: cout<<endl<<"Exiting....";
					break;
			default:cout<<endl<<"Enter a valid Choice";
		}
		//s.menu();
		cout<<endl;
		cout<<endl<<"Enter Choice [0 exit]: ";
		cin>>ch;
		gets(buffer);
	}
	return 0;
}
