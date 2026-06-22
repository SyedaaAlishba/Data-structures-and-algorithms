# CS-451 Data Structures & Algorithms - Weekly Log Summary

## Course Information
- **Course**: CS-451 Data Structures & Algorithms
- **Instructor**: Miss Maryam Feroze
- **Semester**: 2nd Year - 3rd Semester (Session 2024 - 2028)
- **Duration**: 7 January 2026 - 23 April 2026

---

## Week 1: Searching Algorithms

### Topics Covered
- **Linear Search**: Scans elements one by one, works on unsorted data, O(n) time complexity
- **Binary Search**: Uses Divide and Conquer, requires sorted array, O(log n) time complexity

### Lab Tasks
- Linear Search (Single and Multiple Occurrences)
- Binary Search (Single and Multiple Occurrences)

### Home Tasks
- Implement Bubble Sort in C++
- Implement Selection Sort in C++

### Key Insights
- Challenge: Calculating mid-point correctly to avoid overflow
- Understanding why Binary Search is more efficient for large datasets

---

## Week 2: Linked Lists and Insertion Sort

### Topics Covered
- **Nodes**: Building blocks containing Data and Pointer (Next)
- **Linked List vs Array**: Dynamic vs static, non-contiguous memory
- **Basic Functions**: insert(), display()

### Lab Tasks
- Implement insert() function
- Implement display() function

### Home Tasks
- Implement Insertion Sort in C++
- Implement search() in a Linked List

### Key Insights
- Challenge: Managing Head pointer while using temp pointer
- Understanding that losing Head pointer loses the entire list

---

## Week 3: Circular and Doubly Linked Lists

### Topics Covered
- **Circular Linked List**: Last node points to head, useful for CPU scheduling
- **Doubly Linked List (DLL)**: Contains next and prev pointers, allows bidirectional traversal

### Lab Tasks
- Deletion in Singly Linked List
- Circular Linked List (Insert, Display, Search, Delete)
- Doubly Linked List (Insert and Display)

### Home Tasks
- Implement search() for Doubly Linked List
- Implement delete() for Doubly Linked List

### Key Insights
- Challenge: Managing prev pointer in DLL without losing track
- Understanding that Circular lists never reach NULL

---

## Week 4: Multi-linked Lists and Stacks

### Topics Covered
- **Multi-linked List**: Hierarchical structure with Course nodes containing student lists
- **Stacks**: LIFO principle, Push/Pop operations, Array or Linked List implementation

### Lab Tasks
- Multilist Basics (addCourse, addStudentToCourse, displayAll)
- Stack using Linked List (push, pop, display)

### Home Tasks
- Advanced Multilist Operations (deleteCourse, searchCourse, deleteStudentFromAllCourses)
- Stack using Array (with Overflow/Underflow handling)

### Key Insights
- Challenge: Managing "delete student from all courses" logic
- Understanding Stacks as restricted Linked Lists

---

## Week 5: Queue and Hashing

### Topics Covered
- **Queue (FIFO)**: enqueue(), dequeue()
- **Circular Queue**: Uses modulo arithmetic to reuse array space
- **Hashing**: Maps keys to indices using hash function
- **Collision Handling**:
  - Linear Probing: index = (h(key) + i) % size
  - Quadratic Probing: index = (h(key) + i²) % size

### Lab Tasks
- Queue using Dynamic List
- Hash Table using Linear Probing

### Home Tasks
- Circular Queue using Static Array

### Key Insights
- Challenge: Managing front and rear updates in circular queue
- Understanding why collisions degrade performance

---

## Week 6: Advanced Hashing & Recursion

### Topics Covered
- **Quadratic Probing**: Reduces primary clustering but doesn't guarantee visiting all slots
- **Resolution Strategies**: Prime table size, load factor < 0.5, double hashing
- **Load Factor (α)**: α = number of elements / table size
- **Open Hashing (Separate Chaining)**: Each index stores a linked list
- **Quick Sort**: Divide-and-Conquer with pivot selection

### Lab Tasks
- Open Hashing Implementation

### Home Tasks
- Recursive Display of Singly Linked List
- Modify Hashing for Other Data Types

### Conceptual Question
**Stable vs Unstable Sorting**:
- **Bubble Sort**: Stable
- **Insertion Sort**: Stable
- **Selection Sort**: Unstable
- **Merge Sort**: Stable
- **Quick Sort**: Unstable

### Key Insights
- Challenge: Understanding why quadratic probing sometimes fails
- Importance of table size and load factor in hashing efficiency

---

## Week 7: Merge Sort & Binary Search Tree (Theory)

### Topics Covered
- **Merge Sort**: Divide-and-Conquer, stable, requires auxiliary array
- **Binary Search Tree (BST)**:
  - Left subtree < root < Right subtree
  - **Traversals**:
    - Preorder (Root → Left → Right): For copying tree
    - Inorder (Left → Root → Right): Produces sorted order
    - Postorder (Left → Right → Root): For deletion

### Lab Tasks
- Quick Sort Implementation
- Merge Sort Implementation

### Key Insights
- Challenge: Understanding merge process and managing temporary arrays
- Understanding that inorder traversal gives sorted output in BST

---

## Week 8: BST Operations & Expression Trees

### Topics Covered
- **BST Structure**: Node with data, left, right pointers
- **Operator Precedence & Associativity**
- **Expression Trees**: Operands as leaf nodes, operators as internal nodes

### Lab Tasks
- BST Insert and Search
- All Three Traversals

### Key Insights
- Challenge: Managing multiple cases in BST deletion
- Understanding how precedence shapes expression trees

---

## Week 9: Infix to Postfix Conversion

### Topics Covered
- **Infix Expression**: Standard human-readable (a + b * c)
- **Postfix Expression**: Operators after operands (abc*+)
- **Conversion Algorithm**: Uses stack to handle precedence and parentheses
- **Postfix Evaluation**: Stack-based calculation

### Lab Tasks
- Infix to Postfix Implementation

### Key Insights
- Challenge: Managing precedence and correctly popping operators
- Understanding how stack enforces precedence automatically

---

## Week 10: No Class

---

## Week 11: AVL Trees

### Topics Covered
- **AVL Tree**: Self-balancing BST
- **Balance Factor**: BF = height(left) - height(right), allowed values: -1, 0, +1
- **Rotations**:
  - Right Rotation (LL Case)
  - Left Rotation (RR Case)
  - Left-Right Rotation (LR Case)
  - Right-Left Rotation (RL Case)

### Lab Tasks
- Build AVL Tree with values: 120, 110, 150, 130, 140, 146, 136, 134, 160, 154, 156, 132, 125, 128

### Home Tasks
- Implement rotation functions (rightRotate, leftRotate, leftRightRotate, rightLeftRotate)
- AVL Tree Operations (Search, Insert, Delete)

### Key Insights
- Challenge: Identifying correct rotation case
- Understanding how balance factor controls tree height

---

## Week 12 & 13: No Classes

---

## Week 14: Postfix Evaluation, Expression Trees & Heap

### Topics Covered
- **Postfix Evaluation**: Stack-based operand/operator processing
- **Expression Tree from Postfix**: Constructed using stack
- **Heap**: Complete Binary Tree, Max/Min Heap
- **Array Representation**: Parent at i, left child at 2i+1, right child at 2i+2
- **Heapify Operations**:
  - Up-Heapify (Insert): Compare with parent
  - Down-Heapify (Delete): Compare with children
- **Heap Sort**: Build heap, swap root with last, reduce size, down-heapify

### Lab Tasks
- Postfix Evaluation (via Infix Conversion)
- Expression Tree from Postfix
- Heap Implementation

### Key Insights
- Challenge: Understanding heapify direction (up vs down)
- Understanding heap is partially ordered, not fully sorted

---

## Week 15: No Class

---

## Week 16: Graphs & Review

### Topics Covered
- **Graph**: Vertices and Edges
- **Types**: Weighted/Unweighted, Directed/Undirected, Cyclic/Acyclic
- **Connectivity**: Connected (undirected), Strongly Connected (directed)
- **Representations**: Adjacency List (sparse), Adjacency Matrix (dense)
- **Traversals**:
  - BFS: Uses Queue, level by level
  - DFS: Uses recursion/stack, depth-first
- **Spanning Tree**: Connects all vertices with V-1 edges, no cycles

### Lab Tasks
- Graph using Adjacency List (addVertex, addEdge, findDegree, BFS)

### Home Tasks
- Cycle Detection and Path Finding
- DFS Implementation
- Graph using Adjacency Matrix
- Complete Heap and Heap Sort

### Exam Note
- MST (Prim's, Kruskal) and Dijkstra are for step-by-step calculations only, no code implementation required

### Key Insights
- Challenge: Understanding differences between multiple graph algorithms
- Clear distinction between BFS vs DFS and Prim vs Kruskal

---

## Summary of Key Data Structures

| Data Structure | Key Operations | Time Complexity |
|---------------|----------------|-----------------|
| Linear Search | Search | O(n) |
| Binary Search | Search | O(log n) |
| Linked List | Insert, Delete, Search | O(n) |
| Doubly Linked List | Insert, Delete, Search | O(n) |
| Stack | Push, Pop | O(1) |
| Queue | Enqueue, Dequeue | O(1) |
| Circular Queue | Enqueue, Dequeue | O(1) |
| Hash Table (Linear Probing) | Insert, Search | O(1) average |
| Hash Table (Separate Chaining) | Insert, Search | O(1) average |
| Binary Search Tree | Insert, Delete, Search | O(log n) average |
| AVL Tree | Insert, Delete, Search | O(log n) guaranteed |
| Heap | Insert, Delete Max/Min | O(log n) |
| Heap Sort | Sort | O(n log n) |
| Quick Sort | Sort | O(n log n) average |
| Merge Sort | Sort | O(n log n) guaranteed |

---

## Important Formulas

- **Binary Search Mid**: mid = low + (high - low) / 2
- **Hash Index**: index = value % table_size
- **Linear Probing**: index = (h(key) + i) % size
- **Quadratic Probing**: index = (h(key) + i²) % size
- **Load Factor**: α = number of elements / table size
- **AVL Balance Factor**: BF = height(left) - height(right)
- **Heap Array**: Left child = 2i+1, Right child = 2i+2, Parent = (i-1)/2
