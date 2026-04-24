
# 📌 Big Integer Operations using Linked List (C++)

## 📖 Overview

This program implements **big integer arithmetic** using a **singly linked list**. Since standard data types (like `int`, `long long`) have size limits, this program allows handling **very large numbers** by storing each digit in a node.

Each digit of the number is stored separately in a linked list, enabling operations like:

* Addition
* Subtraction

---

## ⚙️ How It Works

### 🔹 1. Representation of Big Integers

* Each digit of the number is stored in a node (`LLNode`).
* Example:
  Number `1234` is stored as:

  ```
  1 → 2 → 3 → 4
  ```
* Before operations, the list is **reversed** to make calculations easier:

  ```
  4 → 3 → 2 → 1
  ```

---

### 🔹 2. Implemented Functions

#### 🧩 `insert(LLNode* &list, string bigInt)`

* Converts a string number into a linked list.
* Each character is converted into a digit and inserted at the end.

---

#### 🔄 `reverse(LLNode* &list)`

* Reverses the linked list.
* Required because arithmetic operations are easier from **least significant digit (LSD)**.

---

#### 🖨️ `display(LLNode* &list)`

* Prints the linked list (digit by digit).

---

#### ➕ `addition(LLNode* &list1, LLNode* &list2, LLNode* &list3)`

* Adds two big integers.
* Uses:

  * Digit-wise addition
  * Carry handling
* Stores result in `list3`.

---

#### ➖ `subtraction(LLNode* &list1, LLNode* &list2, LLNode* &list3)`

* Subtracts second number from first.
* Uses:

  * Borrow mechanism
* Stores result in `list3`.

⚠️ Assumption:

* First number ≥ Second number (otherwise result may be incorrect).

---

## ▶️ Program Flow

1. User enters first big integer
2. It is stored in a linked list
3. List is reversed
4. User enters second big integer
5. Same process is repeated
6. Addition is performed
7. Result is reversed and displayed
8. Subtraction is performed
9. Result is reversed and displayed

---

## 🧪 Sample Input / Output

```
Enter the big integer: 1234
4 3 2 1

Enter the second integer: 567
7 6 5

Addition Result:
1 8 0 1   (i.e., 1801)

Subtraction Result:
6 6 7     (i.e., 667)
```

---

## ⚠️ Limitations

* Subtraction assumes:

  ```
  list1 ≥ list2
  ```
* No handling of negative results
* Inefficient insertion (traverses list every time)
* Leading zeros are not removed in result

---

## 💡 Possible Improvements

* Handle negative results in subtraction
* Optimize insertion using a **tail pointer**
* Remove leading zeros from output
* Support multiplication and division
* Improve memory management (delete unused nodes)

---

## 🛠️ Technologies Used

* Language: **C++**
* Data Structure: **Singly Linked List**

---

## 🎯 Learning Outcome

From this project, you understand:

* How to represent large numbers using linked lists
* How arithmetic operations work internally (carry & borrow)
* Pointer manipulation in linked lists


