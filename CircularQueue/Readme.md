# Circular Queue Implementation (C++)

## Overview

This project implements a **Circular Queue** using arrays in **C++**. The program demonstrates how queue operations can be performed efficiently while reusing empty spaces created after deletions.

A **Circular Queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle, where the first element inserted is the first one to be removed. Unlike a simple queue, the circular queue connects the end of the array back to the beginning, forming a loop.

This structure allows the program to utilize memory efficiently by reusing the spaces freed by dequeued elements.

---

## Features

* Insert elements into the queue (Enqueue)
* Remove elements from the queue (Dequeue)
* Display all elements in the queue
* Demonstrates circular memory reuse
* Fixed-size queue implementation

---

## What is a Circular Queue?

A **Circular Queue** is an advanced form of a linear queue where:

* The last position is connected back to the first position
* The queue forms a circular structure
* Memory that becomes free after deletions can be reused
* It prevents the **false overflow problem** that occurs in simple array queues

The queue operates based on **FIFO (First In, First Out)**.

---

## Real World Applications

Circular queues are widely used in systems that require continuous processing of data.

### 1. CPU Scheduling

Operating systems use circular queues in **Round Robin scheduling** to cycle through processes repeatedly.

### 2. Streaming Data Buffers

Applications like video streaming or audio processing use circular buffers to handle continuous data flow.

### 3. Printer Spooling

Print jobs are managed in queues where each job is processed in the order it arrives.

### 4. Traffic Management Systems

Traffic signals and vehicle processing simulations can use circular queues to manage repetitive cycles.

### 5. Network Data Buffers

Routers and network devices use circular buffers to temporarily store incoming data packets.

---

## Learning Objectives

This project helps in understanding:

* Queue data structure
* FIFO principle
* Circular memory management
* Array-based data structures
* Efficient data handling

It is a good practice project for students studying **Data Structures and Algorithms (DSA)**.

---

## Program Operations

The program demonstrates the following queue operations:

* **Enqueue** – Insert a new element into the queue
* **Dequeue** – Remove an element from the front of the queue
* **Display** – Show all elements currently stored in the queue

The queue automatically wraps around the array when the end is reached, maintaining the circular structure.

---

## Technologies Used

* **C++ Programming Language**
* **Standard Library (iostream)**

---

## Conclusion

This project demonstrates how a **Circular Queue** works and why it is more efficient than a simple linear queue when implemented using arrays. It helps build a strong understanding of queue operations and memory utilization in data structures.

