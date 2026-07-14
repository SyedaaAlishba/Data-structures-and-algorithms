#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* list=NULL;



void sorting_While_Insertion(Node* &root, int value)
{
    Node* temp = new Node();

    temp->data = value;
    temp->next = NULL;

    // Case 1: Empty List
    if(root == NULL)
    {
        root = temp;
        return;
    }

    // Case 2: Insert at Head
    if(value <= root->data)
    {
        temp->next = root;
        root = temp;
        return;
    }

    // Case 3: Insert in Middle or End
    Node* cur = root;

    while(cur->next != NULL && cur->next->data < value)
    {
        cur = cur->next;
    }

    temp->next = cur->next;
    cur->next = temp;
}

Node* CopyReverse(Node* list)
{
    Node* newList = NULL;

    Node* cur = list;

    while(cur != NULL)
    {
        Node* temp = new Node();

        temp->data = cur->data;

        // Insert at Head of New List
        temp->next = newList;
        newList = temp;

        cur = cur->next;
    }

    return newList;
}
void display(Node* root) {
    if(root == NULL) {
        return;
    }
    Node* p = root;
    while(p->next != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << p->data;
}
int main()
{
    sorting_While_Insertion(list,5);
    sorting_While_Insertion(list,6);
    sorting_While_Insertion(list,0);
    sorting_While_Insertion(list,9);
    sorting_While_Insertion(list,2);
    sorting_While_Insertion(list,4);
    cout << "Original List:\n";
    display(list);

    Node* reverseList = CopyReverse(list);

    cout << "\nReverse Copy:\n";
    display(reverseList);

    return 0;

}