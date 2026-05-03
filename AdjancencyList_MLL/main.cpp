#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};


struct Vertex {
    string data;
    Vertex* next;
    Node* adjList;
};

Vertex* head = NULL;


void addVertex(string v) {
    Vertex* newNode = new Vertex();
    newNode->data = v;
    newNode->next = NULL;
    newNode->adjList = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Vertex* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

Vertex* findVertex(string v) {
    Vertex* temp = head;

    while (temp != NULL) {
        if (temp->data == v)
            return temp;
        temp = temp->next;
    }

    return NULL;
}

void addEdge(string from, string to) {
    Vertex* v = findVertex(from);
    if (v == NULL) {
        cout << "Vertex not found\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = to;
    newNode->next = NULL;

    if (v->adjList == NULL) {
        v->adjList = newNode;
        return;
    }

    Node* temp = v->adjList;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}


void displayGraph() {
    Vertex* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";

        Node* adj = temp->adjList;

        if (adj == NULL) {
            cout << "NULL";
        } else {
            while (adj != NULL) {
                cout << adj->data;
                if (adj->next != NULL)
                    cout << " -> ";
                adj = adj->next;
            }
        }

        cout << endl;
        temp = temp->next;
    }
}
int main() {

    addVertex("A");
    addVertex("B");
    addVertex("C");
    addVertex("D");

    addEdge("A", "B");
    addEdge("A", "C");
    addEdge("B", "D");
    addEdge("C", "D");

    displayGraph();

    return 0;
}