#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    float data;
    Node* left;
    Node* right;

    Node(float value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void insert(Node* &root,float value)
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
void mirror(Node* root)
{
    if(root==NULL)
        return;

    swap(root->left,root->right);

    mirror(root->left);
    mirror(root->right);
}
void levelOrder(Node* root)
{
    if(root==NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        cout<<temp->data<<" ";

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }
}
int main()
{
    Node* root = NULL;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter float values:\n";

    for(int i = 0; i < n; i++)
    {
        float value;
        cin >> value;

        insert(root, value);
    }

    cout << "Original Tree (Level Order): ";
    levelOrder(root);

    mirror(root);

    cout << "\nMirror Tree (Level Order): ";
    levelOrder(root);

    return 0;
}