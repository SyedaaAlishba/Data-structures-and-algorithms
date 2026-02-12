#include <iostream>
using namespace std;

#define SIZE 5
int queue[SIZE];
int front = 0;
int rear = 0;
int currentSize = 0;


void EnQueue(int val) {
  if (currentSize== SIZE) {
    cout << "Queue is full" << endl;
    return;
  }
  if (currentSize == 0) {
    front = 0;
    rear = 0;
    queue[rear] = val;
    currentSize ++;
    return;
  }
  rear = (rear + 1) % SIZE;
  queue[rear] = val;
  currentSize ++;

}

void DeQueue() {
  if (currentSize == 0) {
    cout << "Queue is empty" << endl;
    return;
  }
  cout << queue[front] << "De Queuing"<<endl;
  front = (front + 1) % SIZE;
  currentSize --;

}

void display() {
  if (currentSize == 0) {
    cout << "Queue is empty" << endl;
    return;
  }
  int i = front;
  do {
    cout << queue[i] <<endl;
    i = (i + 1) % SIZE;
  } while (i != (rear + 1) % SIZE);

}

int main() {
  EnQueue(1);
  EnQueue(2);
  EnQueue(3);
  EnQueue(4);
  EnQueue(5);
  display();


  cout<<"-----------"<<endl;
  DeQueue();
  DeQueue();
  cout<<"--------"<<endl;
  display();
  cout<<"--------"<<endl;

  EnQueue(6);
  EnQueue(7);
  display();


}