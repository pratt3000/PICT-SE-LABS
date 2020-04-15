package sll;
import lists.Operations;
import java.util.Scanner;

class Node{
    public int data;
    public Node link;

    public Node(){
        data=0;
        link=null;
    }
    public Node(int x){
        data=x;
        link=null;
    }
}


public class SinglyLinkedList implements Operations {
    Node head;
    Node tail;
    int size;

    SinglyLinkedList(){
        head=null;
        tail=null;
        size=0;
    }

    public int isEmpty() {
        if(head == null){
            return 1;
        }
        else{
            return 0;
        }
    }

    public void add(int x){
        Node t= new Node(x);
        if(head == null){
            head = t;
            tail = t;
        }
        else{
            Node p = new Node();
            p=head;
            while(p!=tail){
                p=p.link;
            }
            //now p is pointing on tail node
            p.link = t;
            tail=t;
        }
        size++;
    }
    public void create(){
        Scanner s = new Scanner(System.in);
        while(true) {
            System.out.print("Enter data: ");
            int x = s.nextInt();
            if(x==-1){
                break;
            }
            add(x);
        }
    }
    public void insert(){
        Scanner s = new Scanner(System.in);
            System.out.print("Enter data: ");
            int x = s.nextInt();
            add(x);
    }

    public void size(){
        System.out.println("\n\tSize of list is: " + size);
//        return size;
    }

    public void display(){
        System.out.println("\t\tSingly Linked List :-\n");
        if(head==null){
            System.out.println("\t[Error] List Underflow\n");
        }
        else{
            Node t = new Node();
            t=head;
            System.out.print("\t\t");
            while(t != tail){
                System.out.print("[" + t.data + "] -> " );
                t=t.link;
            }
            System.out.print("[" + t.data + "]" );
        }
    }
    public void search(){
        System.out.print("Enter Data to be searched: ");
        Scanner s = new Scanner(System.in);
        int x = s.nextInt();
        int entryno=0;
        int flag=0;
        Node t = new Node();
        if(head==null){
            System.out.println("[Error] List Underflow");
        }
        else{

            t=head;
            while(t.link!=null){
                entryno++;
                if(t.data == x){
                    flag=1;
                    break;
                }
            }
            if(t.data == x){
                flag=1;
                entryno++;
            }
        }
        if(flag!=1){
            System.out.println("\n\t[Error] Data not found!");
        }
        else{
            System.out.println("\n\tData Found!\nEntry No: " + entryno + "\tData: " + t.data);
        }
    }
    public void remove(){
        int flag=0;
        System.out.print("Enter Data to be deleted: ");
        Scanner s = new Scanner(System.in);
        int d = s.nextInt();
        if(head==null){
            System.out.println("[Error] List Underflow");
        }
        else{
            Node t = new Node();
            Node prev = new Node();
            t=head;
            if(head.data == d){//first node is to be deleted
                flag=1;
                head = head.link;
                t.link=null;
            }
            else{
                prev = head;
                t=head.link;
                while(t.link!=null){

                    if(t.data == d)
                    {
                        prev.link = t.link;
                        t.link=null;
                        flag=1;
                        break;
                    }
//                    prev=t;
                    prev = prev.link;
                    t=t.link;
                }
                //now t is pointing on tail
                if(tail.data == d){
                    prev.link=null;
                    tail=prev;
                    flag=1;
                }
            }
        }
        if(flag!=1){
            System.out.println("\n\t[Error] Data not found!");
        }
        else{
            size--;
        }
    }

    public static void main(String[] args) {
        SinglyLinkedList list = new SinglyLinkedList();
        Scanner cin = new Scanner(System.in);
        int select;
        do {
            System.out.println("\t\t\tMENU\n" + "\t\t1. Create\n" + "\t\t2. Insert\n" + "\t\t3. Remove\n" + "\t\t4. Size\n" + "\t\t5. isEmpty\n" + "\t\t6. Display");
            System.out.print("\t\tEnter Choice :- ");
            int choice = cin.nextInt();
            switch (choice) {
                case 1: {
                    list.create();
                    list.display();
                    break;
                }
                case 2: {
                    list.insert();
                    list.display();
                    break;
                }
                case 3: {
                    list.remove();
                    list.display();
                    break;
                }
                case 4: {
                    list.size();
                    break;
                }
                case 5: {

                    System.out.print("\n\tEmpty Status: ");
                    int r=list.isEmpty();
                    System.out.print(r);
                    break;
                }
                case 6: {
                    list.display();
                    break;
                }

            }
            System.out.print("\n\n\t\tDo you wish to continue?(1/0) : ");
            select = cin.nextInt();
        }while(select==1);
    }
}

/*
	javac -d . Operations.java SinglyLinkedList.java
	java sll.SinglyLinkedList
*/
