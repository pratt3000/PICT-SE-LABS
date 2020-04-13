#include"sets.cpp"
#define A 0
#define B 1

void index(int i=0){
	string set;
	set[0]=char('A'+i);
	set[1]=char('B'-i);
	
	cout<<"\n------------------------------------------------------";
	cout<<"\n\tSET OPERATIONS:";
	cout<<"\n*Selected Set: "<<set[0];
	cout<<"\nPress 1  : Switch Selected Set";
	cout<<"\nPress 2  : Print Set";
	cout<<"\nPress 3  : Add Element";
	cout<<"\nPress 4  : Remove Element";
	cout<<"\nPress 5  : Search for Element";
	cout<<"\nPress 6  : Size()";
	cout<<"\nPress 7  : "<<set[0]<<" Subset of "<<set[1]<<" ?";
	cout<<"\nPress 8  : "<<set[0]<<" union "<<set[1];
	cout<<"\nPress 9  : "<<set[0]<<" intersection "<<set[1];
	cout<<"\nPress 10 : "<<set[0]<<" - "<<set[1];

}

int main(){
	Set<int> *p;
	Set<int> a,b,c;
	int choice,selectedSet;
	
	selectedSet=A;
	p=&a;
	
	index(selectedSet);
	cout<<"\n------------------------------------------------------";
	cout<<"\n\nEnter Choice [0-Exit|99-Index]: ";
	cin>>choice;
	
	while(choice){
		switch(choice){
			char set;
			int data;
			bool flag;
			
			case 1 :	while(true){
							cout<<"\nSelect Set (A/B): ";
							cin>>set;
							if(set=='A' or set=='a'){
								selectedSet=A;
								set='A';
								p=&a;
								index(selectedSet);
								break;
							}
							else if(set=='B' or set=='b'){
								selectedSet=B;
								set='B';
								p=&b;
								index(selectedSet);
								break;
							}
							else
								cout<<"Enter Valid Choice!\n";
						}
						break;
			
			case 2 :	cout<<"\n"<<set<<" = ";
						p->print();
						break;
			
			case 3 :	cout<<"\nEnter Element to Add: ",cin>>data;
						p->add(data);
						cout<<"\n"<<data<<" inserted!";
						break;
						
			case 4 :	cout<<"\nEnter Element to Delete: ",cin>>data;
						flag=p->remove(data);
						if(flag==true)
							cout<<"\n"<<data<<" Deleted!";
						else
							cout<<"\n"<<data<<" Not Found in Set "<<set;
						break;
							
			case 5 :	cout<<"\nEnter Element to Search: ",cin>>data;
						flag=p->contains(data);
						if(flag==true)
							cout<<"\n"<<data<<" Found in Set "<<set;
						else
							cout<<"\n"<<data<<" NOT Found in Set "<<set;
						break;
			
			case 6 :	cout<<"\nSet "<<set<<" contains "<<p->size()<<" Elements";
						break;
				
			case 7 :	if(set=='A'){
							flag=p->isSubset(b);
							if(flag==true)
								cout<<"\nA is Subset of B: True";
							else
								cout<<"\nA is Subset of B: False";
						}
						else{
							flag=p->isSubset(a);
							if(flag==true)
								cout<<"\nB is Subset of A: True";
							else
								cout<<"\nB is Subset of A: False";
						}
						break;
			
			case 8 :	c=a.unification(b);
						cout<<"\nUnion = ";
						c.print();
						break;
			
			case 9 :	c=a.intersection(b);
						cout<<"\nIntersection = ";
						c.print();
						break;
			
			case 10:	if(set=='A'){
							c=p->difference(b);
							cout<<"\nA-B = ";
							c.print();
						}
						else{
							c=p->difference(a);
							cout<<"\nB-A = ";
							c.print();
						}
						break;
			
			case 99:	index(selectedSet);
						break;
			
			default:	cout<<"\nEnter Valid Choice!";				
		}
		cout<<"\n------------------------------------------------------";
		cout<<"\n\nEnter Choice [0-Exit|99-Index]: ";
		cin>>choice;
	}
	cout<<"\nEND..";
	return 0;
}
