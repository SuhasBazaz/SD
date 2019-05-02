#include<iostream>
using namespace std;
class Node
{
        public:
                Node* left;
                Node* right;
                int lbit;
                int rbit;
                int data;
                Node()
                {
                        left = NULL;
                        right = NULL;
                        lbit = 1;
                        rbit = 1;
        
                }

};

class TBT
{
        public:
                Node* root;
                Node* dummy = new Node;

                TBT()
                {
                        root = NULL;
                        dummy->data = -999;
                }
                Node* create(int data);
                void insert(Node* temp, Node* n);
                void display();

};

void TBT::display()
{
        Node* temp = this->root;
        while(temp -> data != -999)
        {
                while(!temp->lbit)
                        temp = temp->left;
                cout<<" "<<temp->data;
                if(temp->rbit == 0)
                        temp = temp->right;
                else
                {
                        temp = temp->right;
                        while(temp->rbit != 0)
                        {
                                cout<<" "<<temp->data;
                                temp = temp -> right;
                        }
                        if(temp->data != -999)
                        cout<<" "<<temp->data;
                        temp = temp->right;
                }
                
                
        }
}
Node* TBT::create(int data) 
{
        Node* temp = new Node;
        temp-> data = data;
        return temp;
}

void TBT::insert(Node* temp, Node* n)
{
        while(temp!= dummy)
        {
                if(this->root == NULL)
                        {
                                root = n;
                                
                                dummy->left = root;
                                dummy->right = dummy;
                                dummy->lbit = 0;
                                dummy->rbit = 0;
                                n->left = dummy;
                                n->right = dummy;
                                n->lbit = 1;
                                n->rbit = 1;
                                return;
                        }
                else if(n->data  < temp->data)
                {
                        if(temp->lbit == 0) 
                                temp = temp->left;
                        else
                        {
                                n -> left = temp -> left;
                                n -> right = temp;
                                n -> lbit = 1;
                                n -> rbit = 1;
                                temp -> lbit = 0;
                                temp -> left = n;
                                return;
                        }
                }

                else if(n->data > temp->data)
                {
                        if(temp->rbit == 0)
                                temp = temp -> right;
                        else
                        {
                                n -> right = temp -> right;
                                n-> rbit = 1;
                                n-> lbit = 1;
                                n -> left = temp;
                                temp -> rbit = 0;
                                temp -> right = n;
                                return;
                        }
                }
        }

}

int main()
{
        int switch_choice;
        char ch = 'y';
        TBT object;
        while(ch == 'y')
        {
                cout<<"\n\t1.INSERT\n\t2.DISPLAY.\n\t3.EXIT"<<endl;

                cin>>switch_choice;
                switch(switch_choice)
                {
                        case 1:
                        {
                                cout<<"ENTER NUMBER OF ELEMENTS TO BE INSERTED."<<endl;
                                int n, temp;
                                cin>>n;
                                cout<<"ENTER THE ELEMENTS."<<endl;
                                for(int i = 0; i<n; i++)
                                {
                                        cin>> temp;
                                        Node* to_insert = object.create(temp);
                                        object.insert(object.root, to_insert);
                                }
                                break;
                        }

                        case 2:
                        {
                                cout<<"\nINORDER TRAVERSAL USING THREADS: ";
                                object.display();
                                break;
                        }
                        case 3:
                        {
                                cout<<"EXITING..."<<endl;
                                ch = 'n';
                        }
                }
        }
        return 0;
}
