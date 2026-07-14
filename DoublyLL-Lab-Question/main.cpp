#include <iostream>
using namespace std;

struct  Node {
    int data;
    Node* next;
    Node* prev;
};
Node* list= NULL;

void insert(Node* &list,int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(list == NULL) {
        list = temp;
        return;
    }
    Node* cur = list;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = temp;
    temp->prev = cur;
    return;
}
void reverse(Node* &list) {
    if(list == NULL) {
        return;
    }

    Node* cur = list;
    Node* temp= NULL;

    while(cur != NULL) {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }
    if (temp!=NULL) {
      list = temp->prev;
    }
}

void display(Node* &list) {
    if(list == NULL) {
        return;
    }
    Node* cur = list;
    while(cur != NULL) {
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    cout<<endl;
}

void findMAXandMIN(Node* &list) {
    if(list == NULL) {
        return;
    }
    Node* cur = list;
    int max = cur->data;
    int min = cur->data;
    while(cur != NULL) {
        if(cur->data > max) {
            max = cur->data;
        }
        if(cur->data < min) {
            min = cur->data;
        }
        cur = cur->next;
    }
    cout<<"max "<<max<<endl;
    cout<<"min "<<min<<endl;

}

void minToFirst(Node* &head, Node* &tail)
{
    if(head==NULL || head->next==NULL)
        return;

    Node* minNode=head;
    Node* cur=head;

    while(cur!=NULL)
    {
        if(cur->data < minNode->data)
            minNode=cur;

        cur=cur->next;
    }

    if(minNode==head)
        return;

    // Remove
    if(minNode->prev!=NULL)
        minNode->prev->next=minNode->next;

    if(minNode->next!=NULL)
        minNode->next->prev=minNode->prev;
    else
        tail=minNode->prev;

    // Insert at head
    minNode->prev=NULL;
    minNode->next=head;
    head->prev=minNode;
    head=minNode;
}
void maxToLast(Node* &head, Node* &tail)
{
    if(head==NULL || head->next==NULL)
        return;

    Node* maxNode=head;
    Node* cur=head;

    while(cur!=NULL)
    {
        if(cur->data > maxNode->data)
            maxNode=cur;

        cur=cur->next;
    }

    if(maxNode==tail)
        return;

    // Remove
    if(maxNode->prev!=NULL)
        maxNode->prev->next=maxNode->next;
    else
        head=maxNode->next;

    if(maxNode->next!=NULL)
        maxNode->next->prev=maxNode->prev;

    // Insert at tail
    maxNode->next=NULL;
    maxNode->prev=tail;
    tail->next=maxNode;
    tail=maxNode;
}

void middleNode(Node* head)
{
    if(head==NULL)
    {
        cout<<"List Empty";
        return;
    }

    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    cout<<"Middle Node = "<<slow->data<<endl;
}
int main() {
cout<<"INSERT IN DOUBLY LL"<<endl;
    insert(list,10);
    insert(list,20);
    insert(list,90);
    insert(list,40);
    insert(list,30);
    insert(list,60);
    display(list);
    cout<<"REVERSE IN DOUBLY LL"<<endl;
    reverse(list);
    display(list);
    findMAXandMIN(list);


}
