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