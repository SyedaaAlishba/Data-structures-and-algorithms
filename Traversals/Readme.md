# 🌳 Tree Traversals in DSA

## 📌 Traversal Types

### 🔵 1. Preorder Traversal (Root → Left → Right)

```cpp
void preOrder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
````

---

### 🟢 2. Inorder Traversal (Left → Root → Right)

```cpp
void inOrder(Node* root) {
    if (root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
```

---

### 🔴 3. Postorder Traversal (Left → Right → Root)

```cpp
void postOrder(Node* root) {
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
```

---

## 🧠 Traversal Summary

| Traversal Type | Order               |
| -------------- | ------------------- |
| Preorder       | Root → Left → Right |
| Inorder        | Left → Root → Right |
| Postorder      | Left → Right → Root |

---

## 🚀 Applications of Tree Traversals

* Binary Search Trees (BST)
* Expression Tree Evaluation
* File System Hierarchy
* Compiler Syntax Trees
* Data Searching & Sorting Problems

---

## 📂 Features

* Simple recursive implementations
* Beginner-friendly code
* Important for DSA interviews
* Helps in understanding tree structures

---



## ⭐ Tip

Practice all three traversals until you can write them without looking. They are the base of almost every tree problem in DSA.

---
