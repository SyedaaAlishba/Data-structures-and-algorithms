//
// Created by PMYLS on 4/23/2026.
//

#ifndef ADJANCENCYLIST_QUEUE_H
#define ADJANCENCYLIST_QUEUE_H
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Check empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue
    void Enqueue(int value) {
        Node* temp = new Node();
        temp->data = value;
        temp->next = nullptr;

        if (rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    // Dequeue
    int Dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        Node* temp = front;
        int value = front->data;

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return value;
    }

    // Peek (optional but useful)
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    // Display (optional)
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

#endif //ADJANCENCYLIST_QUEUE_H