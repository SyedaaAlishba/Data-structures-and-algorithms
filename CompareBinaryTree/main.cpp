#include <iostream>
#include <queue>
using namespace std;
struct Node {
    string data;
    Node* left;
    Node* right;
};
Node* TNode=NULL;

void insert(Node* &root,string value)
{
    if(root==NULL)
    {
        root=new Node(value);
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        if(temp->left==NULL)
        {
            temp->left=new Node(value);
            return;
        }
        else
        {
            q.push(temp->left);
        }

        if(temp->right==NULL)
        {
            temp->right=new Node(value);
            return;
        }
        else
        {
            q.push(temp->right);
        }
    }
}
bool isEqual(Node* t1, Node* t2)
{
    if(t1==NULL && t2==NULL)
        return true;

    if(t1==NULL || t2==NULL)
        return false;

    if(t1->data!=t2->data)
        return false;

    return isEqual(t1->left,t2->left) &&
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

bool isMirror(Node* t1,Node* t2)
{
    if(t1==NULL && t2==NULL)
        return true;

    if(t1==NULL || t2==NULL)
        return false;

    if(t1->data!=t2->data)
        return false;

    return isMirror(t1->left,t2->right)
        &&
        isMirror(t1->right,t2->left);
}

int main() {
    Node* T1=NULL;
    Node* T2=NULL;

    int n1, n2;

    cout << "Enter number of nodes in Tree 1: ";
    cin >> n1;

    cout << "Enter values for Tree 1:\n";

    for(int i = 0; i < n1; i++)
    {
        string value;
        cin >> value;
        insert(T1, value);
    }

    cout << "\nEnter number of nodes in Tree 2: ";
    cin >> n2;

    cout << "Enter values for Tree 2:\n";

    for(int i = 0; i < n2; i++)
    {
        string value;
        cin >> value;
        insert(T2, value);
    }

    if(isEqual(T1,T2))
        cout<<"Equal Trees";
    else
        cout<<"Not Equal";

    if(sameStructure(T1,T2))
        cout<<"\nSame Structure";
    else
        cout<<"\nDifferent Structure";

    if(isMirror(T1,T2))
        cout<<"\nMirror Trees";
    else
        cout<<"\nNot Mirror";
}