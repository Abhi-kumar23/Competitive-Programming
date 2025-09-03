# Boundary Traversal of Binary Tree

This project demonstrates **boundary traversal** of a binary tree in C++.

---

## Problem

Given a binary tree, print its **boundary traversal**:

1. Root node
2. Left boundary (excluding leaves)
3. Leaf nodes (left to right)
4. Right boundary (excluding leaves, in reverse order)

---

## Solution

- Check if a node is a leaf.
- Traverse left boundary top-down.
- Traverse leaf nodes recursively.
- Traverse right boundary bottom-up.
- Time complexity: O(n), n = number of nodes.

---

## How to Run

1. Clone the repository:

```bash
git clone <your-repo-url>
