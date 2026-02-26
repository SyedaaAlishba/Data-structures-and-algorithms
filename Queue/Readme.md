
# 📌 Queue Implementation Using Linked List 

## 📖 Overview

This program implements a **Queue data structure** using a **Singly Linked List** in C++.
A queue follows the **FIFO (First In, First Out)** principle:

> 🔹 The element inserted first is removed first.

---

## ❓ Where is Queue Used?

Queues are used in many **real-world and computer science problems**, such as:

* 🖨️ **Printer queue** (documents printed in order)
* 🎟️ **Ticket booking systems**
* 🧵 **CPU scheduling**
* 🌐 **Request handling in servers**
* 📡 **Data buffering**
* 🚦 **Traffic systems**
* 📊 **Breadth First Search (BFS)** in graphs

---

## 🧠 What This Code Does

This code creates a **dynamic queue** using a **linked list**, instead of an array.
It allows:

* Adding elements (**Enqueue**)
* Removing elements (**Dequeue**)
* Displaying the queue (**Display**)

---

## 🏗️ Data Structure Used

### 🔹 Node Structure

```cpp
struct Node {
    int data;
    Node* next;
};
```

Each node contains:

* `data` → stores the value
* `next` → points to the next node

---

## 🔗 Queue Pointers

```cpp
Node* front = nullptr;
Node* rear = nullptr;
```

* **front** → points to the first element
* **rear** → points to the last element

---

## ➕ Enqueue Operation

```cpp
void Enqueue(int value)
```

### 📌 Purpose:

Adds an element **at the end of the queue**

### 🛠️ Logic:

* Create a new node
* If queue is empty:

  * `front` and `rear` both point to the new node
* Otherwise:

  * Attach new node after `rear`
  * Move `rear` to the new node

✔️ Time Complexity: **O(1)**

---

## ➖ Dequeue Operation

```cpp
void Dequeue()
```

### 📌 Purpose:

Removes an element **from the front of the queue**

### 🛠️ Logic:

* If queue is empty → show error
* Otherwise:

  * Store `front` in temp
  * Move `front` to next node
  * Delete temp
* If queue becomes empty:

  * Set `rear = nullptr`

✔️ Time Complexity: **O(1)**

---

## 👀 Display Operation

```cpp
void display()
```

### 📌 Purpose:

Displays all elements in the queue from **front to rear**

### 🛠️ Logic:

* Traverse linked list starting from `front`
* Print each node’s data

✔️ Time Complexity: **O(n)**

---

## ▶️ Main Function Flow

```cpp
int main() {
    Dequeue();          // Queue empty check
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);

    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();          // Extra dequeue (empty case)

    Enqueue(7);
    Dequeue();
    display();
}
```

### 🧪 What This Tests:

* Dequeue from empty queue
* Multiple enqueue operations
* Multiple dequeue operations
* Edge case: dequeue more than available elements
* Queue reuse after becoming empty

---

## ✅ Advantages of Linked List Queue

* ✔️ No fixed size (dynamic)
* ✔️ Efficient memory usage
* ✔️ No shifting of elements (unlike array queue)

---

## 📌 Conclusion

This program demonstrates a **fully functional Queue** using **Linked List** with proper handling of:

* Empty queue
* Insertion
* Deletion
* Display

Perfect for:

* 📚 Data Structures learning
* 🧑‍🎓 Semester projects
* 🧠 Understanding pointers & dynamic memory


