import java.util.Stack;
import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Collections {
	Scanner read= new Scanner(System.in);
	void index()
	{
		int choice,flag=0;
		while(flag!=1)
		{
			System.out.println("\n1.Linked List \n2.Stack \n3.Priority Queue \n4.Dequeue \n5.HashSet \n0.Exit");
			choice=read.nextInt();
			switch(choice)
			{
			case 1:
				linkedListIndex();
				break;
				
			case 2:
				stackIndex();
				break;
				
			case 3:
				queueIndex();
				break;
				
			case 4:
				dequeueIndex();
				break;
				
			case 5:
				hashSetIndex();
				break;
				
			case 0:
				flag=1;
				return;
				
				
				default:
					System.out.println("Enter valid choice!!");
					break;
			}
		}
	}
	
	
	public void linkedListIndex()
	{
		LinkedList<Integer> l= new LinkedList<Integer>();
		int choice,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Add First \n2.Add Last \n3.Remove First \n4.Remove Last \n5.Display whole list \n0.Exit");
			choice=read.nextInt();
			switch(choice)
			{
			case 1:
				System.out.println("Enter data to be added in list-: ");
				data=read.nextInt();
				l.addFirst(data);
				break;
				
			case 2:
				System.out.println("Enter data to be added in list-: ");
				data=read.nextInt();
				l.addLast(data);
				break;
				
			case 3:
				l.removeFirst();
				break;
				
			case 4:
				l.removeLast();
				break;
				
			case 5:
				System.out.println("Contents of Linked List are-: "+l);
				break;
				
			case 0:
				flag=1;
				break;
				
				default:
					System.out.println("Enter valid choice!!");
					break;
			}
		} 
	}
	
	
	public void stackIndex()
	{
		Stack<Integer> st=new Stack<>();
		int choice,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Push \n2.Pop \n3.Display Top \n4.IsEmpty \n0.Exit");
			choice=read.nextInt();
			switch(choice)
			{
			case 1:
				System.out.println("Enter data to be added in list-: ");
				data=read.nextInt();
				st.push(data);
				break;
				
			case 2:
				System.out.println("Data popped from stack is-: " +st.pop());
				break;
				
			case 3:
				System.out.println("Data at top of stack is-: " +st.peek());
				break;
				
			case 4:
				if(st.isEmpty())
				{
					System.out.println("Stack is Empty!!");
				}
				else
				{
					System.out.println("Stack is not empty!!");
				}
				break;
			case 0:
				flag=1;
				break;
				
			default:
				System.out.println("Enter valid choice!!");
				break;
			}
		}	 
	}
	
	
	public void queueIndex()
	{
		PriorityQueue<Integer> pq= new PriorityQueue<Integer>();
		int choice,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Add Data \n2.Pop \n3.Display head \n4.size \n0.Exit");
			choice=read.nextInt();
			switch(choice)
			{
			case 1:
				System.out.println("Enter data to be added in Priority Queue-: ");
				data=read.nextInt();
				pq.add(data);
				break;
				
			case 2:
				System.out.println("Data popped from Priority Queue is-: " +pq.poll());
				break;
				
			case 3:
				System.out.println("Data at top of Priority Queue is-: " +pq.peek());
				break;
				
			case 4:
				System.out.println("Size of Priority Queue is-: " +pq.size());
				break;
			case 0:
				flag=1;
				break;
				
			default:
				System.out.println("Enter valid choice!!");
				break;
			}
		} 
	}
	
	
	public void dequeueIndex()
	{
		ArrayDeque<Integer> dq= new ArrayDeque<Integer>();
		int choice,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Add First \n2.Add last \n3.Display head \n4.Display Tail \n5.Remove First \n6.Remove Last \n0.Exit");
			choice=read.nextInt();
			switch(choice)
			{
			case 1:
				System.out.println("Enter data to be added in Deque-: ");
				data=read.nextInt();
				dq.addFirst(data);
				break;
				
			case 2:
				System.out.println("Enter data to be added in Deque-: ");
				data=read.nextInt();
				dq.addLast(data);
				break;
				
			case 3:
				System.out.println("Element at first position is-:  "+dq.peekFirst());
				break;
				
			case 4:
				System.out.println("Element at last position is-:  "+dq.peekLast());
				break;
				
			case 5:
				System.out.println("Data removed from front is-: " +dq.pollFirst());
				break;
				
			case 6:
				System.out.println("Data removed from Last is-: " +dq.pollLast());
				break;
				
			case 0:
				flag=1;
				break;
				
			default:
				System.out.println("Enter valid choice!!");
				break;
			}
		} 
	}
	
	
	public void hashSetIndex()
	{
		HashSet<Integer> hs= new HashSet<Integer>();
		int choice,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Add element \n2.Remove element \n3.Display whole \n4.size\n0.Exit");
			choice=read.nextInt();
			switch(choice)
			{
			case 1:
				System.out.println("Enter data to be added in HashSet-: ");
				data=read.nextInt();
				hs.add(data);
				break;
				
			case 2:
				System.out.println("Enter data to be removed from Deque-: ");
				data=read.nextInt();
				hs.remove(data);
				break;
				
			case 3:
				System.out.println("Elements in whole Hashset are-:  "+hs);
				break;
				
			case 4:
				System.out.println("Size of HashSet is-:  "+hs.size());
				break;
				
			case 0:
				flag=1;
				break;
				
			default:
				System.out.println("Enter valid choice!!");
				break;
			}
		}	
	}
	
	 
	public static void main(String[] args)
	{
		Collections obj= new Collections();
		obj.index();
	}
}
