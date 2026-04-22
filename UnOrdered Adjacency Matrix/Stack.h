#ifndef UNORDERED_ADJACENCY_MATRIX_STACK_H
#define UNORDERED_ADJACENCY_MATRIX_STACK_H
class Stack {
#define  SIZE 100
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == SIZE - 1;
    }

    void push(int x) {
        if (!isFull()) {
            arr[++top] = x;
        }
    }

    void pop() {
        if (!isEmpty()) {
            top--;
        }
    }

    int peek() {
        if (!isEmpty())
            return arr[top];
        return -1; // ya koi safe value
    }
};
#endif //UNORDERED_ADJACENCY_MATRIX_STACK_H