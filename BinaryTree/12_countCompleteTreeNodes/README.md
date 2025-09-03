# Count Complete Binary Tree Nodes

This project demonstrates how to count the number of nodes in a **complete binary tree** efficiently using C++.

---

## Problem

Given a **complete binary tree**, return the total number of nodes in the tree.

A **complete binary tree** is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

---

## Solution

- If the left and right heights are equal, the tree is **perfect**, and the number of nodes = 2^height - 1.
- Otherwise, recursively count the nodes of the left and right subtrees.
- Time complexity: O((log n)^2) for a complete binary tree.

---

## How to Run

1. Clone the repository:

```bash
git clone <your-repo-url>
