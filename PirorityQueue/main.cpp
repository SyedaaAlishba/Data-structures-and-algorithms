#include <iostream>
using namespace std;

struct Node
{
    string task;
    int priority;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// Enqueue according to priority
void Enqueue(string task, int priority)
{
    Node* temp = new Node();

    temp->task = task;
    temp->priority = priority;
    temp->next = NULL;

    // Queue Empty
    if(front == NULL)
    {
        front = rear = temp;
        return;
    }

    // Highest priority -> Insert at Front
    if(priority > front->priority)
    {
        temp->next = front;
        front = temp;
        return;
    }

    Node* cur = front;

    // Traverse until correct position
    // >= is used so same priority follows FIFO
    while(cur->next != NULL && cur->next->priority >= priority)
    {
        cur = cur->next;
    }

    temp->next = cur->next;
    cur->next = temp;

    // Update rear if inserted at end
    if(temp->next == NULL)
    {
        rear = temp;
    }
}

// Dequeue
void Dequeue()
{
    if(front == NULL)
    {
        cout << "Queue is Empty\n";
        return;
    }

    Node* temp = front;

    cout << "Removed Task: "
         << front->task
         << "  Priority: "
         << front->priority << endl;

    front = front->next;

    if(front == NULL)
    {
        rear = NULL;
    }

    delete temp;
}

// Display Queue
void Display()
{
    if(front == NULL)
    {
        cout << "Queue is Empty\n";
        return;
    }

    Node* cur = front;

    cout << "\nPriority Queue:\n";

    while(cur != NULL)
    {
        cout << cur->task
             << " (Priority "
             << cur->priority
             << ")\n";

        cur = cur->next;
    }
}

int main()
{
    int n;

    cout << "Enter number of tasks: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string task;
        int priority;

        cout << "\nEnter Task Name: ";
        cin >> task;

        cout << "Enter Priority: ";
        cin >> priority;

        Enqueue(task, priority);
    }

    Display();

    cout << "\nDequeuing...\n";
    Dequeue();

    Display();

    return 0;
}