# 📘 Binary Search Tree (BST) 

## 📌 What is this program?

This program implements a **Binary Search Tree (BST)** in **C++**.
It allows you to:

* Insert values into a BST
* Search for a value
* Delete a node using **recursive deletion**
* Traverse the tree in **Preorder, Inorder, and Postorder**

---

## 🌳 What is a Binary Search Tree (BST)?

A **Binary Search Tree** is a tree-based data structure where:

* Each node has **at most 2 children**
* **Left child < Parent**
* **Right child > Parent**

This property makes searching, insertion, and deletion **efficient**.

---

## 🎯 When is BST used?

BST is used when you need:

* Fast **searching** (better than arrays)
* Sorted data handling
* Dynamic data (insert/delete at runtime)

Common use cases:

* Databases
* File systems
* Symbol tables
* Search engines (basic structure)

---

## 🧩 What components are in this code?

### 1️⃣ Node Structure

Each node contains:

* `data` → the value
* `left` → pointer to left child
* `right` → pointer to right child

This represents **one element** of the tree.

---

### 2️⃣ Insert Function

**Purpose:**
Adds a new value into the BST following BST rules.

**How it works:**

* If tree is empty → new node becomes root
* If value < current node → goes to left subtree
* If value > current node → goes to right subtree
* Uses **recursion** to find correct position

---

### 3️⃣ Search Function

**Purpose:**
Checks whether a value exists in the BST.

**How it works:**

* Starts from root
* If value is smaller → move left
* If value is greater → move right
* Stops when:

  * Value is found 
  * Or tree ends 

It prints:

* `"VALUE FOUND"` if present
* `"NOT FOUND"` if not present

---

### 4️⃣ minValue Function

**Purpose:**
Finds the **smallest value** in a subtree.

**How it works:**

* In a BST, the smallest value is always at the **leftmost node**
* This function keeps moving left until no more left child exists

This is mainly used during **deletion of a node with two children**.

---

### 5️⃣ DeleteNode Function 

**Purpose:**
Deletes a node from the BST **recursively**.

It handles **all 3 deletion cases**:

#### Case 1: Leaf Node (no children)

* Node is simply deleted
* Parent pointer is set to `NULL`

#### Case 2: Node with One Child

* Child replaces the deleted node
* Tree remains connected

#### Case 3: Node with Two Children

This is the tricky case:

* Find **inorder successor** (smallest value in right subtree)
* Copy successor’s value into current node
* Recursively delete the successor node

👉 This keeps BST rules intact.

---

### 6️⃣ Tree Traversals

Traversals are used to **visit all nodes** in different orders.

#### 🔹 Preorder Traversal

Order:

```
Root → Left → Right
```

Used when:

* You want to **copy the tree**
* Or see tree structure

---

#### 🔹 Inorder Traversal

Order:

```
Left → Root → Right
```

Special thing:

* **In BST, inorder traversal gives sorted output**

---

#### 🔹 Postorder Traversal

Order:

```
Left → Right → Root
```

Used when:

* You want to **delete the tree**
* Or evaluate expressions

---

## ▶️ What happens in `main()`?

In `main()`:

1. A BST is created
2. Multiple values are inserted
3. Search is performed for:

   * One missing value
   * One existing value
4. Tree is printed using:

   * Preorder
   * Postorder
   * Inorder
5. A node is deleted
6. Tree is printed again to show updated structure

---

## 🧠 Key Concepts Used in This Code

* Recursion
* Pointers
* Dynamic memory (`new` / `delete`)
* Binary Search Tree rules
* Tree traversal techniques

---

## ⭐ Why this code is important for learning?

This code helps you understand:

* Real **tree-based data structures**
* How recursion works in **real problems**
* How complex operations like deletion are handled safely
* Foundation for **DSA interviews & exams**

---

