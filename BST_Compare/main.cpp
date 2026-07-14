#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
void insert(Node* &root,int value)
{
    if(root==NULL)
    {
        root=new Node(value);
        return;
    }

    if(value < root->data)
        insert(root->left,value);
    else
        insert(root->right,value);
}
bool isEqual(Node* t1,Node* t2)
{
    if(t1==NULL && t2==NULL)
        return true;

    if(t1==NULL || t2==NULL)
        return false;

    if(t1->data!=t2->data)
        return false;

    return isEqual(t1->left,t2->left)
        &&
        isEqual(t1->right,t2->right);
}
bool sameStructure(Node* t1,Node* t2)
{
    if(t1==NULL && t2==NULL)
        return true;

    if(t1==NULL || t2==NULL)
        return false;

    return sameStructure(t1->left,t2->left)
        &&
        sameStructure(t1->right,t2->right);
}
void descending(Node* root)
{
    if(root==NULL)
        return;

    descending(root->right);

    cout<<root->data<<" ";

    descending(root->left);
}
int main()
{
    Node* T1=NULL;
    Node* T2=NULL;

    int n1,n2;

    cout<<"Enter number of nodes in Tree 1: ";
    cin>>n1;

    cout<<"Enter values:\n";

    for(int i=0;i<n1;i++)
    {
        int x;
        cin>>x;
        insert(T1,x);
    }

    cout<<"Enter number of nodes in Tree 2: ";
    cin>>n2;

    cout<<"Enter values:\n";

    for(int i=0;i<n2;i++)
    {
        int x;
        cin>>x;
        insert(T2,x);
    }

    if(isEqual(T1,T2))
        cout<<"\nTrees are Equal";
    else
        cout<<"\nTrees are Not Equal";

    if(sameStructure(T1,T2))
        cout<<"\nTrees have Same Structure";
    else
        cout<<"\nTrees have Different Structure";

    cout<<"\n\nTree 1 Descending Order:\n";
    descending(T1);

    cout<<"\n\nTree 2 Descending Order:\n";
    descending(T2);

    return 0;
}