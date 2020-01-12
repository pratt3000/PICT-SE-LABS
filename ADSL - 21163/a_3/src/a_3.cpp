#include <iostream>
using namespace std;
class Node{
    Node *left, *right;
    bool rflag, lflag;
    int value;
public:
    Node(int val){
        left = NULL;
        right = NULL;
        value = val;
        rflag = 0;
        lflag = 0;
    }
    friend class Tree;
};
class Tree{
    Node *q, *root;
public:
    friend class node;
    Tree(){
        q = NULL;
        root = NULL;
    }
    void add(){
            int val;
            bool side;
            int flag;
            Node *r, *l;
            r = NULL;
            l = NULL;
            if(root == NULL){
                cout<<"enter node value(100 :- exit) : ";
                cin>>val;
                root = new Node(val);
                goto set;
            }
            else{
                set:
                cout<<"\nEnter node value(100 :- exit) : ";
                cin>>val;
                if(val == 100){
                    return;
                }
                r = NULL;
                l = NULL;
                q = root;
                flag = 0;
                while(1){
                    cout<<"L/R node?(0/1) : ";
                    cin>>side;
                    if(side == 1 ){
                        r = q;
                        if(q->right == NULL || q->rflag == 1 ){
                            cout<<"NULL node found/";
                            q->right = new Node(val);
                            flag = 1;
                            q->rflag = 0;
                        }
                        q = q->right;
                    }
                    else if(side == 0){
                        l = q;
                        if(q->left == NULL || q->lflag == 1 ){
                            cout<<"NULL node found/";
                            q->left = new Node(val);
                            flag = 1;
                            q->lflag = 0;
                        }
                        q = q->left;
                    }
                    if(flag == 1){
                        if(r != NULL && q->left == NULL){
                            q->left = r;
                            q->lflag = 1;
                        }
                        if(l != NULL && q->right == NULL){
                            q->right = l;
                            q->rflag = 1;
                        }
                        goto set;
                    }
                }
            }
        }
    // add works - inorder traversal has some error
    void traversal(int choice){
            if(root == NULL){
                cout<<"empty tree";
                return;
            }
        Node *rt1 = root;
        while(rt1->left ){
            rt1 = rt1->left;
        }
            if(choice == 0)
                inorder_recursive(rt1);
            if(choice == 1)
                preorder_recursive(root);
            if(choice == 2)
                postorder_recursive(root);
        }
    void inorder_recursive(Node *rt){
        while(rt->value != 0){
            cout<<rt->value<<" ";
            inorder_recursive(rt -> right);
        }
    }
    void preorder_recursive(Node *rt){
        if(rt != NULL){
            cout<<rt->value<< " ";
            preorder_recursive(rt->left);
            preorder_recursive(rt->right);
        }
    }
    void postorder_recursive(Node *rt){
        if(rt != NULL){
            postorder_recursive(rt->left);
            postorder_recursive(rt->right);
            cout<<rt->value<<" ";
        }
    }
    void test(){
        //tree tested
        /*
                      2
               3            1
           7      6             5
           
        */
        cout<<root->value<<endl;//2
        cout<<root->left->value<<endl;//3
        cout<<root->left->left->value<<endl;//7
        cout<<root->left->right->value<<endl<<endl;//6
        
        cout<<root->right->value<<endl;//1
        cout<<root->right->right->value<<endl<<endl;//5
        
        cout<<root->right->right->left->value<<endl;//1
        cout<<root->right->right->left->left->value<<endl;//2
        cout<<root->left->left->right->value<<endl;//3
        cout<<root->left->right->left->value<<endl;//3
        cout<<root->left->right->right->value<<endl<<endl;//2
        
        cout<<root->right->right->right<<endl;//1
        cout<<root->left->left->left<<endl;//7

        
    }
};
int main() {
    Tree obj1,obj2, copy1;
        Tree *obj = &obj1;
        int cont = 1;
        int choice;
        cout<<"\n 1:ADD NODE ";                //DONE
        cout<<"\n 2:IN-ORDER";                //DONE
        cout<<"\n 3:PRE-ORDER";                //DONE
        cout<<"\n 4:POST-ORDER";            //DONE
        cout<<"\n99:END";
        while(cont){
            cout<<"\n--- enter choice :  ";
            cin>>choice;
            switch(choice){
                case 1:
                    obj->add();
                    break;
                case 2:
                    obj->traversal(0);
                    cout<<endl;
                    break;
                case 3:
                    obj->traversal(1);
                    cout<<endl;
                    break;
                case 4:
                    obj->traversal(2);
                    cout<<endl;
                    break;
                case 5:
                    obj->test();
                    break;
                case 99:
                    cont = 0;
                    break;
                default:break;
            }
        }
        cout<<"\n~ TERMINATED";
        return 0;
}
