
# 🌳 Level Order Traversal (BFS) in Binary Tree

This repository contains the implementation of **Level Order Traversal** (also known as Breadth First Search - BFS) for a binary tree in C++.

---

## 📌 What is Level Order Traversal?

👉 Level Order Traversal visits nodes **level by level from top to bottom**.

Example:

```

    1
   / \
  2   3
 / \
4   5

```

👉 Output:
```

1 2 3 4 5

````

---

## 🧠 Idea

- Use a **Queue (FIFO)**
- Start from root
- Push children of each node into queue
- Process nodes level by level


## 🔥 Key Points

* Uses **Breadth First Search (BFS)**
* Requires a **queue data structure**
* Time Complexity: **O(n)**
* Space Complexity: **O(n)**

---

## 📊 Difference from DFS Traversals

| Traversal Type | Order               | Technique       |
| -------------- | ------------------- | --------------- |
| Preorder       | Root → Left → Right | DFS (Recursion) |
| Inorder        | Left → Root → Right | DFS (Recursion) |
| Postorder      | Left → Right → Root | DFS (Recursion) |
| Level Order    | Level by Level      | BFS (Queue)     |

---

## 🚀 Applications

* Tree visualization
* Shortest path in unweighted tree
* Network broadcasting
* Hierarchical data processing

---

## ⭐ Tip

👉 Always remember:

> DFS = Stack/Recursion
> BFS = Queue



