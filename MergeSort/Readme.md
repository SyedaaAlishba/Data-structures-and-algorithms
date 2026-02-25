
# 📘 Merge Sort 

## 📌 What is this program?

This program implements the **Merge Sort algorithm** in **C++**.
It takes an unsorted array of integers and sorts it in **ascending order** using the **divide and conquer technique**.

---

## 🔍 What is Merge Sort?

**Merge Sort** is a **comparison-based sorting algorithm** that works by:

1. Dividing the array into smaller subarrays
2. Sorting those subarrays recursively
3. Merging the sorted subarrays back into one sorted array

Unlike simple sorting algorithms, Merge Sort is **efficient and reliable**, especially for large datasets.

---

## 🎯 When should Merge Sort be used?

Merge Sort is used when:

* You need **guaranteed performance**
* Worst-case time complexity matters
* Stable sorting is required
* You are working with **large data sets**

Common use cases:

* Sorting large files
* External sorting (data doesn’t fit in memory)
* Foundation for advanced algorithms
* Academic learning of divide-and-conquer

---

## 🧠 Core Idea Behind Merge Sort

Merge Sort follows the **Divide and Conquer** strategy:

### 🔹 Divide

Split the array into two halves until each part has only one element.

### 🔹 Conquer

Single-element arrays are already sorted.

### 🔹 Combine

Merge the sorted halves step by step to form a fully sorted array.

---

## 🧩 What components are in this program?

### 1️⃣ `mergeSort` Function

**Purpose:**
Handles the **recursive division** of the array.

**What it does:**

* Checks the base case (0 or 1 element)
* Finds the middle of the array
* Recursively sorts left and right halves
* Calls the merge function to combine results

---

### 2️⃣ `merge` Function

**Purpose:**
Combines two **already sorted subarrays** into one sorted array.

**What it does:**

* Uses a temporary array to store sorted values
* Compares elements from both halves
* Copies remaining elements if one half finishes early
* Copies the sorted data back into the original array

👉 This is the function where **actual sorting happens**.

---

### 3️⃣ `main` Function

**Purpose:**
Acts as the **entry point** of the program.

**What it does:**

* Creates an unsorted array
* Calls `mergeSort` to sort the array
* Prints the sorted result

---

## 🔁 Program Flow (High-Level)

1. Program starts from `main`
2. `mergeSort` divides the array recursively
3. Division continues until single elements remain
4. `merge` combines sorted subarrays
5. Final sorted array is produced and displayed

---

## ⏱️ Time and Space Complexity

| Aspect       | Value      |
| ------------ | ---------- |
| Best Case    | O(n log n) |
| Average Case | O(n log n) |
| Worst Case   | O(n log n) |
| Extra Space  | O(n)       |
| Stable Sort  | Yes        |

---

## ⭐ Advantages of Merge Sort

* Predictable performance
* Works efficiently on large data
* Stable sorting algorithm
* Easy to understand recursion logic

---

## ⚠️ Limitations

* Requires extra memory (temporary array)
* Slower for very small arrays compared to simpler sorts

---

## 🧠 Key Concepts Used

* Recursion
* Divide and Conquer
* Array manipulation
* Temporary storage
* Algorithm analysis

