#include <iostream>
using namespace std;

struct  Node {
    int data;
    Node* next;
    Node* prev;
};

void insert(int data) {
    Node * list = new Node();
    list->prev = NULL;
    list->next = NULL;

    if (list->next == NULL) {
        list->data =data;
    }
    

}
int main() {





}





















