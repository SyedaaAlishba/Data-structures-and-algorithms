# Max Heap Implementation in C++

This project demonstrates the implementation of a **Max Heap** using arrays in C++.

## 📖 Overview

A **Max Heap** is a complete binary tree in which the value of every parent node is greater than or equal to the values of its children. The largest element is always stored at the root.

This program allows:

- Insertion of elements into a Max Heap
- Automatic heap construction using Heapify-Up
- Deletion of the maximum element (root)
- Re-heapification using Heapify-Down

---

## ⚙️ Concepts Used

- Arrays
- Binary Trees
- Heap Data Structure
- Heapify Up
- Heapify Down
- Insertion in Heap
- Deletion in Heap

---

## 📝 Functions

### `insert()`
Inserts a new element into the heap and restores the heap property using **Heapify-Up**.

### `heapifyDown()`
Restores the heap property after deletion by moving the root element downward to its correct position.

### `deleteMax()`
Removes and returns the maximum element (root node) from the heap.

---

## 🚀 Sample Input

```text
Enter size of heap: 5

Enter elements:
10
20
15
30
40


Max Heap: 40 30 15 10 20

Deleted max: 40

Heap after deletion: 30 20 15 10
