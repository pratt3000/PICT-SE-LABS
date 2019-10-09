//asssignment 1
//roll no:21163
//name   :prathamesh sonawane

#include<iostream>
using namespace std;
class student
{
	int rn;
	float marks;
	char name[100];
public:
	void read();
	void display();
	float gtm();
	int gtrn();
	char* gtn();
};
void student::read()
{

	cout<<"\n enter name:";
		cin>>name;
		rnn:
	cout<<"\n enter roll number";
	cin>>rn;
	if(rn<=0)
			{
			cout<<"\n----------------------------------------\n enter valid entry\n -----------------------------------------------------";
			goto rnn;
			}
	cout<<"\n enter marks(-ve if absent)";
	cin>>marks;

}
void student::display()
{
	cout<<" \n roll number:"<<rn<<"\n";
	cout<<" marks:"<<marks<<"\n";
	cout<<" name:"<<name<<"\n-----------------------------------------------------------";
}

float student::gtm()
		{return marks;}
	char* student::gtn()
		{return name;}
	int student::gtrn()
		{return rn;}


class ds
{
	int n,i,j;
	student s[10];
public:
	void read()
	{x:
		cout<<"\n enter no. of students";
		cin>>n;
		if(n<=0)
		{
			cout<<"\n enter valid entry";
					goto x;
		}
		cout<<"\n";
		for(i=0;i<n;i++)
		{
			s[i].read();

		}
	}
	void display()
	{
		for(i=0;i<n;i++)
		{
			s[i].display();

		}
	}

	float avg()
	{
		float avg=0;
		if(s[i].gtm()>=0)
		{
		for(i=0;i<=n;i++)
		{
			if(s[i].gtm()>=0)
			{
				avg=avg+s[i].gtm();
			}
		}
		}
		int abs=0;
			for(i=0;i<=n;i++)
			{
				if(s[i].gtm()<0)
					abs++;
			}
		avg=avg/(n-abs);
		return avg;
	}

	float max()
		{
			float max=s[0].gtm();
			for(i=0;i<n;i++)
			{
				if(s[i].gtm()>=0)
				{
					if( max<s[i].gtm())
						max=s[i].gtm();
				}
			}
			return max;
		}

	float min()
			{
				float min=s[0].gtm();
				for(i=0;i<n;i++)
				{
					if(s[i].gtm()>=0)
					{
						if( min>s[i].gtm())
							min=s[i].gtm();
					}
				}
				return min;
			}
	float abs()
	{
	int abs=0;
	for(i=0;i<=n;i++)
	{
		if(s[i].gtm()<0)
			abs++;
	}
	return abs;
	}

	float most()
	{

		float m[10];
		int j;
		for(j=0;j<=n;j++)
		{
			if(s[j].gtm()<0)
			m[j]=-1;
			else
			m[j]=0;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(s[i].gtm()>=0 && s[j].gtm()>0)
				if(s[i].gtm()==s[j].gtm())
				{
					m[i]++;

				}
			}
		}
		float max=m[0];
		int i;
		for(i=0;i<n;i++)
					{
						if(m[i]>=0)
						{
							if( max<m[i])
								{max=m[i];
								}
						}
					}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(m[i]==m[j])
					m[j]=-1;
			}
		}

		for(i=0;i<n;i++)
		{

			if(max==m[i] && m[i]>=0)
			{
				cout<<"most common marks"<<s[i].gtm()<<"\n";
			}
		}
		return max;
	}
};

int main()
{
	abc:
int x,e=1;
ds ob;
cout<<"ENTER DATA \n ---------------------------------------------------------------------";
ob.read();
ob.display();
while( e==1)
{
cout<<" \n 1:average\n 2:max and min \n 3:absent students \n 4:most common marks\n 5:re enter\n 6: \n";
cin>>x;
switch (x)
	{
	case 1: cout<<"\n average="<<ob.avg();
		break;
	case 2:cout<<"\n max="<<ob.max();
		cout<<"\n min="<<ob.min()<<"\n";
		break;
	case 3:cout<<"\n absent="<<ob.abs();
	break;
	case 4:cout<<" frequency= "<<ob.most();
	break;
	case 5:goto abc;
	default: break;
	}
cout<<"\n do you want to continue?(1/0) \n ";
cin>>e;
}
cout<<"END";
}

/*ENTER DATA
 ---------------------------------------------------------------------
 enter no. of students7


 enter name:rt

 enter roll number5

 enter marks(-ve if absent)10

 enter name:ty

 enter roll number6

 enter marks(-ve if absent)-9

 enter name:er

 enter roll number4

 enter marks(-ve if absent)30

 enter name:ty

 enter roll number5

 enter marks(-ve if absent)100

 enter name:g

 enter roll number6

 enter marks(-ve if absent)30

 enter name:t

 enter roll number5

 enter marks(-ve if absent)-9

 enter name:g

 enter roll number4

 enter marks(-ve if absent)-77

 roll number:5
 marks:10
 name:rt
-----------------------------------------------------------
 roll number:6
 marks:-9
 name:ty
-----------------------------------------------------------
 roll number:4
 marks:30
 name:er
-----------------------------------------------------------
 roll number:5
 marks:100
 name:ty
-----------------------------------------------------------
 roll number:6
 marks:30
 name:g
-----------------------------------------------------------
 roll number:5
 marks:-9
 name:t
-----------------------------------------------------------
 roll number:4
 marks:-77
 name:g
-----------------------------------------------------------
 1:average
 2:max and min
 3:absent students
 4:most common marks
 5:re enter
 6:
1

 average=42.5
 do you want to continue?(1/0)
 1

 1:average
 2:max and min
 3:absent students
 4:most common marks
 5:re enter
 6:
2

 max=100
 min=10

 do you want to continue?(1/0)
 1

 1:average
 2:max and min
 3:absent students
 4:most common marks
 5:re enter
 6:
3

 absent=3
 do you want to continue?(1/0)
 1

 1:average
 2:max and min
 3:absent students
 4:most common marks
 5:re enter
 6:
4
most common marks30
 frequency= 2
 do you want to continue?(1/0)
 1

 1:average
 2:max and min
 3:absent students
 4:most common marks
 5:re enter
 6:
5
ENTER DATA
 ---------------------------------------------------------------------
 enter no. of students



