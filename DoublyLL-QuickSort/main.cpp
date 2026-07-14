#include <algorithm>
#include <iostream>
using namespace std;

struct  Node {
    int data;
    Node* next;
    Node* prev;
    int index;
};
Node* list= NULL;
Node* tail= NULL;
int countNode = 0;

void insert(Node* &list,int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    temp->index = countNode;
    countNode++;
    if(list == NULL) {
        list = temp;
        tail = temp;
        return;
    }
    Node* cur = list;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = temp;
    temp->prev = cur;
    tail = temp;
}

int countNODE() {
    return countNode;
}
void display(Node* list) {
    Node* cur = list;
    if(list == NULL) {
        cout<<"List is empty"<<endl;
    }
    else {
        while(cur!= NULL) {
            cout<<cur->data<<" ";
            cur= cur->next;
        }

    }
}

Node* partition(Node* low, Node* high)
{
    int pivot = high->data;

    Node* i = low->prev;

    for(Node* j = low; j != high; j = j->next)
    {
        if(j->data <= pivot)
        {
            if(i == NULL)
                i = low;
            else
                i = i->next;

            swap(i->data, j->data);
        }
    }

    if(i == NULL)
        i = low;
    else
        i = i->next;

    swap(i->data, high->data);

    return i;
}

void QuickSort(Node* low, Node* high)
{
    if(high != NULL &&low != high && low != high->next)
    {
        Node* pivot = partition(low, high);

        QuickSort(low, pivot->prev);
        QuickSort(pivot->next, high);
    }
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insert(list, value);
    }

    cout << "\nOriginal List:\n";
    display(list);

    QuickSort(list, tail);

    cout << "\n\nSorted List:\n";
    display(list);

    cout << "\n\nTotal Nodes: " << countNODE() << endl;

    return 0;
}