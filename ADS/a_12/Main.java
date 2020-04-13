import java.util.*;
abstract class Stack{
	public final void pushTemplate(){
        pop();
        push();
        display();
    	}
	abstract protected void push();
	abstract protected void display();
	abstract protected void pop();
} 
class MyException extends Exception{
	public MyException(String s){
		super(s);
	}
}
class IntegerStack extends Stack{
	int stack[]=new int[10];		//Size of Stack taken as 10
	int top=-1;
	protected void push(){
		try{
			if(top==1){
				throw new MyException("Error");
			}
			System.out.println("Enter Number: ");
			Scanner sc = new Scanner(System.in);
			int data = sc.nextInt();
			top++;
			stack[top]=data;		
		}
		catch(MyException e){
			System.out.println("Stack Full");
		}
		
	}
	protected void pop(){
		try{
			if(top==-1){
				throw new MyException("Error");
			}
			top--;
		}
		catch(MyException e){
			System.out.println("Stack Empty");
		}
	}
	protected void display(){
		System.out.println("Stack is: ");
		for(int i=0;i<=top;i++){
			System.out.print(stack[i] + " ");
		}
	}
}
class CharStack extends Stack{
	char stack[]=new char[10];	//Size of Stack taken as 10
	int top=-1;
	protected void push(){
		try{
			if(top==1){
				throw new MyException("Error");
			}
			System.out.println("Enter Number: ");
			Scanner sc = new Scanner(System.in);
			char data = sc.next().charAt(0);
			top++;
			stack[top]=data;		
		}
		catch(MyException e){
			System.out.println("Stack Full");
		}
		
	}
	protected void pop(){
		try{
			if(top==-1){
				throw new MyException("Error");
			}
			top--;
		}
		catch(MyException e){
			System.out.println("Stack Empty");
		}
	}
	protected void display(){
		System.out.println("Stack is: ");
		for(int i=0;i<=top;i++){
			System.out.print(stack[i] + " ");
		}
	}
}
class Main{
	public static void main(String[] args){
		Stack obj = new CharStack();
		Stack obj2 = new IntegerStack();
		int choice,flag=0;
		System.out.print("1)Add Integer\n2)Add Character\n3)Pop Integer\n4)Pop Character\n5)Exit\n");
		do{
			System.out.println("\nEnter Choice: ");
			Scanner s = new Scanner(System.in);
			choice = s.nextInt();
			switch(choice){
				case 1: obj2.push();
					obj2.display();
					break;
				case 2: obj.push();
					obj.display();
					break;
				case 3: obj2.pop();
					obj2.display();
					break;
				case 4: obj.pop();
					obj.display();
					break;
			     default:	flag=1;
					break;
			}		
		}while(flag==0);	
	}
}
