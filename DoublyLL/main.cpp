#include <iostream>
using namespace std;

struct  Node {
    int data;
    Node* next;
    Node* prev;
};
Node* list=NULL;


void insert(int data) {
    Node * node = new Node();
    node->prev = NULL;
    node->next = NULL;
    node->data = data;
    //empty
    if (list == NULL) {
        list=node;
        return;
    }
    //1st node
    if (list->next == NULL) {
        list->next=node;
        node->prev=list;
        return;
    }

    Node * temp = list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
    node->next = NULL;
}

void display() {
    Node * temp = list;
    if (temp==NULL) {
        cout<<"List is empty"<<endl;
        return;
    }
    while (temp->next!= NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    if (temp->next == NULL) {
      cout<<temp->data<<" ";
    }
}
void search(int data) {
    Node * temp = list;
    if (temp==NULL) {
        cout<<"List is empty"<<endl;
        return;
    }
    while (temp->next != NULL) {
        if (temp->data == data) {
            cout<<"FOUND "<<endl;
            return;
        }
        temp = temp->next;
    }
    if (temp->data == data) {
        cout<<"FOUND "<<endl;
        return;
    }
}
void del(int data) {
    if (list == NULL) return;   // empty list

    Node *temp = list;

    // 🔹 CASE 1: Delete HEAD
    if (temp->data == data) {
        list = temp->next;          // move head forward

        if (list != NULL)           // if list not empty after delete
            list->prev = NULL;

        free(temp);
        return;
    }

    // 🔹 Traverse to find node
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    // If data not found
    if (temp == NULL) return;

    // 🔹 CASE 2 & 3: Middle OR Tail

    // If it's not the last node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // If it's not the first node (already handled head earlier)
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

int main() {


insert(10);
    insert(20);
    insert(30);
    insert(40);
    display();
    search(10);
    del(10);
    display();
    cout<<endl;
    del(40);
    display();


}























