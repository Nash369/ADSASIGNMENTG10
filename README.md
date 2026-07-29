# Smart Photo Storage Management System

## Project Description

This project demonstrates the comparison between a baseline approach and an optimized approach for managing photos using different algorithms and abstract data structures (ADS).

The repository contains:
- `BaselineApproach.cpp` - Traditional implementation using brute force, linear search, and immediate deletion.
- `OptimisedApproach.cpp` - Optimized implementation using Hash Table, Binary Search Tree (BST), and Queue.

---

## Requirements

- C++ compiler (g++ or Visual Studio)
- C++11 or later

---

## How to Run

### Option 1: Using Visual Studio

1. Open Visual Studio.
2. Create a new C++ Console Application.
3. Replace the generated source file with either:
   - `BaselineApproach.cpp`, or
   - `OptimisedApproach.cpp`
4. Build and run the project.

### Option 2: Using g++

Compile the baseline program:

```bash
g++ BaselineApproach.cpp -o baseline
./baseline
```

Compile the optimized program:

```bash
g++ OptimisedApproach.cpp -o optimized
./optimized
```

---

## Features

### Baseline Approach
- Duplicate Detection (Brute Force)
- Photo Search (Linear Search)
- Immediate Photo Deletion

### Optimized Approach
- Duplicate Detection (Hash Table)
- Photo Organization and Search (Binary Search Tree)
- Batch Photo Deletion (Queue)

---
