#include <iostream>
using namespace  std;

struct Node {
    int data;
    Node * next;
};


#define SIZE 5
Node * temp[SIZE];

void init() {
    for(int i=0;i<SIZE;i++) {
        temp[i] = NULL;
    }
}

int hashFunction(int key) {
    return key%SIZE;
}

void insert(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;

    int index = hashFunction(data);

    // If bucket is empty, just insert
    if (temp[index] == NULL) {
        temp[index] = node;
    } else {
        // Insert at head for collision
        node->next = temp[index];
        temp[index] = node;
    }
}


void search(int data) {
    int index= hashFunction(data);
    if (temp[index] == NULL) {
        cout<<"Not Found"<<endl;
        return;
    }
    Node * ptr = temp[index];
    while (ptr != NULL) {
        if (ptr->data == data) {
            cout<<"Found"<<endl;
            return;
        }
        ptr = ptr->next;
    }
    cout<<"Not Found"<<endl;
}
void del(int data) {
    int index = hashFunction(data);

    if (temp[index] == NULL) {
        cout << "Not Found" << endl;
        return;
    }

    Node* ptr = temp[index];
    Node* prev = NULL;

    while (ptr != NULL) {
        if (ptr->data == data) {
            if (prev == NULL) {
                // Node to delete is head
                temp[index] = ptr->next;
            } else {
                // Node is in middle or end
                prev->next = ptr->next;
            }
            delete ptr;
            cout << "Deleted" << endl;
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    cout << "Not Found" << endl;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << "Bucket " << i << ": ";
        Node* ptr = temp[i];
        while (ptr != NULL) {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
}

int main() {
    init();
    insert(10);
    insert(20);
    insert(30);
    insert(41);
    insert(51);
    insert(64);
    display();
    search(10);
    search(30);
    del(10);
    del(20);
    display();

}