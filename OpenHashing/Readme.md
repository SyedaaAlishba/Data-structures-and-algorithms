
# Hash Table Using Separate Chaining (Conceptual Overview)

## 📌 What This Program Is About

This program demonstrates how a **hash table** works using **separate chaining** as a collision-handling technique.

A hash table is a data structure that allows **fast storage, searching, and deletion** of data by converting a value (key) into an index using a **hash function**.

---

## 🧠 Key Idea: Hashing

* A **hash function** takes a value and converts it into an index.
* This index decides **where the data will be stored** in the table.
* In this program, the hash function uses **modulo division** to calculate the index.

---

## ⚠️ What Is a Collision?

A **collision** happens when:

* Two or more values produce the **same hash index**.

Example:
If table size is 5

* 10 % 5 = 0
* 20 % 5 = 0

Both values want to go into **bucket 0** → collision occurs.

---

## 🔗 How Separate Chaining Solves Collisions

Instead of overwriting data:

* Each bucket stores a **linked list**
* All values that map to the same index are stored **one after another**

So:

* Each index can store **multiple values**
* No data is lost due to collisions

---

## 📂 Structure of the Hash Table

* The hash table is an **array of buckets**
* Each bucket points to the **head of a linked list**
* Every linked list node stores:

  * The value
  * A pointer to the next node

---

## 🔍 Operations Performed

### 1️⃣ Insertion

* The value is converted into an index using the hash function
* If the bucket is empty → value is stored directly
* If the bucket already has values → new value is added at the beginning of the linked list

### 2️⃣ Searching

* The hash function gives the bucket index
* The linked list at that index is traversed
* If the value exists → “Found”
* Otherwise → “Not Found”

### 3️⃣ Deletion

* The hash function identifies the correct bucket
* The linked list is searched
* If the value is found:

  * It is removed safely
  * Memory is freed
* If not found → appropriate message is shown

### 4️⃣ Display

* Shows all buckets
* Displays linked list values in each bucket
* Helps visualize how data is distributed

---

## ⭐ Advantages

✔ Very fast searching compared to arrays and linked lists
✔ Handles collisions efficiently
✔ Insert and delete operations are simple
✔ Easy to understand and implement

---

## ❌ Limitations

✘ Performance depends on hash function
✘ Too many collisions can slow down operations
✘ Fixed size hash table (no rehashing)

---

## 🌍 Where Hash Tables Are Used (Real-World Applications)

### 🔐 1. Password Storage

* Usernames are hashed
* Passwords are compared using hash values

### 🌐 2. Databases

* Indexing records for fast search
* Used internally by DBMS systems

### 🧠 3. Caching Systems

* Browser cache
* CPU cache
* Memory management

### 📚 4. Dictionaries & Maps

* Word → Meaning
* Key → Value pairs

### 🕸 5. Networking

* Routing tables
* IP address mapping

### 🎮 6. Game Development

* Storing player data
* Quick lookup of objects

### 🧾 7. Compilers & Interpreters

* Symbol tables
* Variable name lookup

---

## 🎯 Learning Outcome

This program helps in understanding:

* How hash tables work internally
* How collisions are handled
* Why hash tables are powerful and widely used


