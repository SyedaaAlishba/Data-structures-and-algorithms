// Implement BST, insert values in it. Zero and negative are valid values.
// Convert BST into an array. Now use array and display contents using preorder traversal.
// Search a value in array without using linear search, use BST search

#include <iostream>
using namespace std;

int arr[100];
int index = 0;

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
    {
        insert(root->left,value);
    }
    else
    {
        insert(root->right,value);
    }
}
void BSTtoArray(Node* root)
{
    if(root == NULL)
        return;

    arr[index] = root->data;
    index++;

    BSTtoArray(root->left);
    BSTtoArray(root->right);
}
void displayArray()
{
    for(int i = 0; i < index; i++)
    {
        cout << arr[i] << " ";
    }
}
bool Search(Node* root, int value)
{
    if(root == NULL)
        return false;

    if(root->data == value)
        return true;

    if(value < root->data)
        return Search(root->left, value);

    return Search(root->right, value);
}

int main()
{
    Node* root = NULL;

    insert(root,1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    insert(root,5);
    insert(root,6);

    // BST ko Array me convert karo
    BSTtoArray(root);

    int x;
    cout << "Enter value to search: ";
    cin >> x;

    if(Search(root, x))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    cout << "ARRAY:\n";
    displayArray();

    return 0;
}