//============================================================================
// Name        : MINI_PROJECT.cpp
// Author      : Prathamesh Sonawane
// Version     : 1.02
// Architecture: Singleton
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class xo{
		char a;
		char b;
		char c;
		char d;
		char e;
		char f;
		char g;
		char h;
		char i;
		static int sign;
		int ip;
		char ch;
public:
		xo();
		void display();
		bool change();
		bool input();
		void fileload();
};
int xo :: sign;
xo :: xo(){
			 a='1';
			 b='2';
			 c='3';
			 d='4';
			 e='5';
			 f='6';
			 g='7';
			 h='8';
			 i='9';
			 sign  = 1;
			 ip=1;
			 ch='X';
}

void xo :: fileload(){
	ofstream out;
	out.open("matrix.txt",ios::out|ios::in|ios::app);
	out<<"    "<<"|"<<"    "<<"|"<<endl;
	out<<" "<<a<<"  "<<"|"<<" "<<b<<"  "<<"|"<<"  "<<c<<endl;
	out<<"____"<<"|"<<"____"<<"|"<<"____"<<endl;
	out<<"    "<<"|"<<"    "<<"|"<<endl;
	out<<" "<<d<<"  "<<"|"<<" "<<e<<"  "<<"|"<<"  "<<f<<endl;
	out<<"____"<<"|"<<"____"<<"|"<<"____"<<endl;
	out<<"    "<<"|"<<"    "<<"|"<<endl;
	out<<" "<<g<<"  "<<"|"<<" "<<h<<"  "<<"|"<<"  "<<i<<endl;
	out<<"   "<<" |"<<"   "<<" |"<<endl;
}
void xo :: display(){
	cout<<"    "<<"|"<<"    "<<"|"<<endl;
	cout<<" "<<a<<"  "<<"|"<<" "<<b<<"  "<<"|"<<"  "<<c<<endl;
	cout<<"____"<<"|"<<"____"<<"|"<<"____"<<endl;
	cout<<"    "<<"|"<<"    "<<"|"<<endl;
	cout<<" "<<d<<"  "<<"|"<<" "<<e<<"  "<<"|"<<"  "<<f<<endl;
	cout<<"____"<<"|"<<"____"<<"|"<<"____"<<endl;
	cout<<"    "<<"|"<<"    "<<"|"<<endl;
	cout<<" "<<g<<"  "<<"|"<<" "<<h<<"  "<<"|"<<"  "<<i<<endl;
	cout<<"   "<<" |"<<"   "<<" |"<<endl;
}
bool xo :: change(){
	if(a=='X' && e=='X' && i=='X')  {cout<<"WINNER IS X";return 1;}
	else if(a=='X' && b=='X' && c=='X')  {cout<<"WINNER IS X";return 1;}
	else if(d=='X' && e=='X' && f=='X')  {cout<<"WINNER IS X";return 1;}
	else if(g=='X' && h=='X' && i=='X')  {cout<<"WINNER IS X";return 1;}
	else if(c=='X' && e=='X' && g=='X')  {cout<<"WINNER IS X";return 1;}
	else if(a=='X' && d=='X' && g=='X')  {cout<<"WINNER IS X";return 1;}
	else if(b=='X' && e=='X' && h=='X')  {cout<<"WINNER IS X";return 1;}
	else if(c=='X' && f=='X' && i=='X')  {cout<<"WINNER IS X";return 1;}

/// O NOW

	else if(a=='O' && b=='O' && c=='O')  {cout<<"WINNER IS O";return 1;}
	else if(a=='O' && e=='O' && i=='O')  {cout<<"WINNER IS O";return 1;}
	else if(d=='O' && e=='O' && f=='O')  {cout<<"WINNER IS O";return 1;}
	else if(g=='O' && h=='O' && i=='O')  {cout<<"WINNER IS O";return 1;}
	else if(c=='O' && e=='O' && g=='O')  {cout<<"WINNER IS O";return 1;}
	else if(a=='O' && d=='O' && g=='O')  {cout<<"WINNER IS O";return 1;}
	else if(b=='O' && e=='O' && h=='O')  {cout<<"WINNER IS O";return 1;}
	else if(c=='O' && f=='O' && i=='O')  {cout<<"WINNER IS O";return 1;}

	else		return 0;
}
bool xo :: input(){
	if(sign == 1)		{cout<<"chance of X\n"; ch = 'X';}
	if(sign == -1)		{cout<<"chance of O\n"; ch = 'O';}
	int flag = 1;
	while(flag==1){
		cout<<"ENTER POSITION:";
		cin>>ip;
		if(ip==1){
			if(a!='X' && a!='O'){
				a=ch; sign *= -1; flag = 0;return 1;
			}
			else return 0;
		}
		else if(ip==2){
					if(b!='X' && b!='O'){
						b=ch; sign *= -1; flag = 0;return 1;
					}
					else return 0;
				}
		else if(ip==3){
					if(c!='X' && c!='O'){
						c=ch; sign *= -1; flag = 0;return 1;
					}
					else return 0;
				}
		else if(ip==4){
					if(d!='X' && d!='O'){
						d=ch; sign *= -1; flag = 0;return 1;
					}
					else return 0;
				}
		else if(ip==5){
					if(e!='X' && e!='O'){
						e=ch; sign *= -1; flag = 0;return 1;
					}
					else return 0;
				}
		else if(ip==6){
					if(f!='X' && f!='O'){
						f=ch; sign *= -1; flag = 0;return 1;
					}
					else return 0;
				}
		else if(ip==7){
					if(g!='X' && g!='O'){
						g=ch; sign *= -1; flag = 0;return 1;
					}
					else return 0;
				}
		else if(ip==8){
					if(h!='X' && h!='O'){
						h=ch; sign *= -1; flag = 0;return 1;
					}
					else return 0;
				}
		else if(ip==9){
					if(i!='X' && i!='O'){
						i=ch; sign *= -1; flag = 0;
						return 1;
					}
					else return 0;
				}
	}
	return 0;
}

void classobject(){
	int x,y;
		xo ob;
		int t=9;
		ob.display();

		while(t--){
			x=ob.input();
			if(!x){
				cout<<"\nENTER AGAIN : \n";
				t++;
			}
			ob.display();
			y=ob.change();
			if(y){
				cout<<"\n~end";
				ob.fileload();

				break;
			}
		}
}

int main() {
	classobject();
	return 0;
}
