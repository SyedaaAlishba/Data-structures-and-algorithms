# Binary Search

Binary Search is an efficient searching algorithm used to find a specific element in a **sorted array or list**.

---

## 📌 What is Binary Search?

Binary Search works by **dividing the search space into half** on each step.
Instead of checking elements one by one, it compares the target value with the **middle element** of the array and decides which half to continue searching in.

---

##  Why Binary Search is Used❓

Binary Search is used because it is:

* Faster than Linear Search
* Efficient for large datasets
* Reduces the number of comparisons
* Optimized for sorted data

---

## 🧠 How Binary Search Works

1. Start with two pointers: `left` and `right`
2. Find the middle element of the array
3. Compare the middle element with the target value
4. If they are equal, the search is successful
5. If the target is smaller, search the left half
6. If the target is greater, search the right half
7. Repeat until the element is found or the range becomes empty

---

## ⚠ Important Condition

* Binary Search **only works on sorted arrays**
* Using it on an unsorted array will give incorrect results

---

## ⏱ Time and Space Complexity

* **Time Complexity:** O(log n)
* **Space Complexity:** O(1)

---

## ✅ When to Use Binary Search

* When the data is already sorted
* When fast searching is required
* When working with large datasets

---

## ❌ When Not to Use Binary Search

* When the data is unsorted
* When frequent insertions and deletions are needed

---



## ✨ Maintained By

**Syeda Alishba**
Student, UBIT – University of Karachi

