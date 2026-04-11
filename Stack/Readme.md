# 📚 Stack Implementation using Linked List (C++)

## 🔹 What is a Stack?

A **Stack** is a linear data structure that follows the principle of:

> **LIFO (Last In, First Out)**

This means the last element inserted into the stack is the first one to be removed.

### 🧠 Simple Example:

Think of a stack like a pile of plates:

* You **add (push)** plates on top
* You **remove (pop)** plates from the top

---

## 🔹 Basic Operations

* **Push** → Insert an element onto the stack
* **Pop** → Remove the top element from the stack
* **Peek/Top** → View the top element (not implemented here)
* **isEmpty** → Check if the stack is empty

---

## 🔹 Where are Stacks Used?

Stacks are widely used in computer science and real-world applications:

### 💻 Programming & Systems

* Function calls (Call Stack)
* Recursion handling
* Memory management

### 🧮 Expression Handling

* Infix → Postfix conversion
* Postfix expression evaluation

### 🌐 Software Features

* Undo/Redo operations (e.g., in editors like Word)
* Browser history navigation

### 🔍 Algorithms

* Depth First Search (DFS)
* Backtracking (e.g., maze solving)

---

## 🔹 About This Project

This project demonstrates a **Stack implementation using a Linked List in C++**.

### ⚙️ Key Features

* Dynamic memory allocation (no fixed size limit)
* Menu-driven interface
* Basic stack operations: Push and Pop

---

## 🔹 Program Overview (What’s Included)

* A **node structure** to store data and pointer to next node
* A **global pointer (`top`)** to keep track of the stack’s top element
* Implementation of:

  * Push operation
  * Pop operation
* A **menu-based main function** that allows user interaction

---

## 🔹 How to Run

1. Compile the code:

   ```bash
   g++ stack.cpp -o stack
   ```
2. Run the program:

   ```bash
   ./stack
   ```

---

## 🔹 Sample Menu

```
WELCOME TO STACK WORLD :)
1. PUSH TO STACK
2. POP TO STACK
3. EXIT
```

---

## 🔹 Notes

* This implementation uses a **linked list**, so stack size grows dynamically.
* Only basic operations are implemented for simplicity.
