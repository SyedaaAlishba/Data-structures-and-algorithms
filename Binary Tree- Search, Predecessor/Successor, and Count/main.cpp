#include <iostream>
using namespace std;

struct Node
{
    float data;
    Node* left;
    Node* right;

    Node(float val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct QNode
{
    Node* data;
    QNode* next;
};

QNode* front = NULL;
QNode* rear = NULL;

void Enqueue(QNode* &front, QNode* &rear, Node* value)
{
    QNode* temp = new QNode();
    temp->data = value;
    temp->next = NULL;

    if(front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}
Node* Dequeue(QNode* &front, QNode* &rear)
{
    if(front == NULL)
        return NULL;

    QNode* temp = front;
    Node* value = front->data;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    delete temp;

    return value;
}
bool isEmpty(QNode* front)
{
    return front == NULL;
}

void display()
{
    if(front == NULL)
    {
        cout << "Queue is empty\n";
        return;
    }

    QNode* temp = front;

    while(temp != NULL)
    {
        cout << temp->data->data << " ";
        temp = temp->next;
    }
}
Node* Front(QNode* front)
{
    if(front == NULL)
    {
        return NULL;
    }

    return front->data;
}


//Level By Level Insert
void insert(Node* &root, float value)
{
    if(root == NULL)
    {
        root = new Node(value);
        return;
    }

    QNode* front = NULL;
    QNode* rear = NULL;

    Enqueue(front, rear, root);

    while(!isEmpty(front))
    {
        Node* temp = Front(front);
        Dequeue(front, rear);

        if(temp->left == NULL)
        {
            temp->left = new Node(value);
            return;
        }
        else
        {
            Enqueue(front, rear, temp->left);
        }

        if(temp->right == NULL)
        {
            temp->right = new Node(value);
            return;
        }
        else
        {
            Enqueue(front, rear, temp->right);
        }
    }
}

bool Search(Node* root, float value)
{
    if(root == NULL)
        return false;

    if(root->data == value)
        return true;

    return Search(root->left, value) || Search(root->right, value);
}

void predecessorANDSuccessor(Node* &root, float value)
{
    if(root == NULL)
    {
        return;
    }

    // Local Queue
    QNode* front = NULL;
    QNode* rear = NULL;

    Enqueue(front, rear, root);

    bool found = false;
    cout << "Predecessors:\n";
    while(!isEmpty(front))
    {
        Node* cur = Front(front);
        Dequeue(front, rear);

        if(found)
        {
            cout << cur->data << " ";
        }
        else if(cur->data == value)
        {
            found = true;
            cout << "\nSuccessors:\n";
        }
        else
        {
            cout << cur->data << "  ";
        }

        if(cur->left != NULL)
            Enqueue(front, rear, cur->left);

        if(cur->right != NULL)
            Enqueue(front, rear, cur->right);
    }

    if(!found)
    {
        cout << "Element not found";
    }
}

int countNodes(Node* root)
{
    if(root==NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int findLevel(Node* root,float x,int level)
{
    if(root==NULL)
        return -1;

    if(root->data==x)
        return level;

    int left=findLevel(root->left,x,level+1);

    if(left!=-1)
        return left;

    return findLevel(root->right,x,level+1);
}

Node* findNode(Node* root,float x)
{
    if(root==NULL)
        return NULL;

    if(root->data==x)
        return root;

    Node* left=findNode(root->left,x);

    if(left!=NULL)
        return left;

    return findNode(root->right,x);
}
int findHeight(Node* root) {
    if(root==NULL) {
        return -1;
    }
    return 1 + max(findHeight(root->left),findHeight(root->right));
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

    float x;
    cout << "\nEnter value to search: ";
    cin >> x;

    if(Search(root, x))
        cout << "FOUND";
    else
        cout << "NOT FOUND";

    cout << "\n\nPredecessors and Successors:\n";
    predecessorANDSuccessor(root, x);

    cout << "Total Nodes = " << countNodes(root);

    int level=findLevel(root,x,0);

    if(level==-1)
        cout<<"Not Found";
    else
        cout<<"Level = "<<level;

    Node* temp=findNode(root,x);

    if(temp==NULL)
        cout<<"Not Found";
    else
        cout<<"Height = "<<findHeight(temp);
    return 0;
}