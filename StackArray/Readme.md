# 📚 Stack Implementation using Array (C++)

## 🔹 What is a Stack?

A **Stack** is a linear data structure that works on the principle of:

> **LIFO (Last In, First Out)**

The last element added to the stack is the first one to be removed.

### 🧠 Example:

Imagine stacking books:

* You place a book on top (**push**)
* You remove the top book first (**pop**)

---

## 🔹 Types of Stack Implementations

1. **Array-based Stack** (This project ✅)
2. Linked List-based Stack

This project uses a **fixed-size array** to implement the stack.

---

## 🔹 Features of This Implementation

* Fixed size stack using array
* Overflow and underflow handling
* Menu-driven program
* Supports:

  * Push
  * Pop
  * Display

---

## 🔹 Stack Operations

### 📥 Push

Adds an element to the top of the stack.

### 📤 Pop

Removes the top element from the stack.

### 👁️ Display

Shows all elements from **top to bottom**.

### ⚠️ Overflow

Occurs when trying to push into a **full stack**.

### ⚠️ Underflow

Occurs when trying to pop from an **empty stack**.

---

## 🔹 Where are Stacks Used?

Stacks are extremely important in computer science:

### 💻 Programming

* Function call management (Call Stack)
* Recursion handling

### 🧮 Expression Evaluation

* Postfix evaluation
* Infix to postfix conversion

### 🌐 Applications

* Undo/Redo functionality
* Browser navigation history

### 🔍 Algorithms

* Depth First Search (DFS)
* Backtracking problems

---

## 🔹 About This Program

This program demonstrates a **stack using an array of fixed size (SIZE = 5)**.

### ⚙️ Key Components

* **Array (`stackArr`)** to store elements
* **Top variable (`top`)** to track the current top index
* Helper functions:

  * Overflow check
  * Underflow check
* Core operations:

  * Push
  * Pop
  * Display
* Interactive **menu system**

---

## 🔹 How to Run

1. Compile the code:

   ```bash
   g++ stack_array.cpp -o stack
   ```

2. Run the program:

   ```bash
   ./stack
   ```

---

## 🔹 Sample Menu

WELCOME TO ARRAY STACK WORLD :)

1. PUSH
2. POP
3. DISPLAY
4. EXIT

---

## 🔹 Example Scenario

* Push: 10, 20, 30
* Display → `30 20 10`
* Pop → removes `30`

---

## 🔹 Limitations

* Fixed size (**cannot grow dynamically**)
* May cause **overflow** if capacity is exceeded

---

## 🔹 Future Improvements

* Convert into **dynamic stack using linked list**
* Add **peek (top element)** function
* Add **size tracking**
* Implement using **templates (generic stack)**

