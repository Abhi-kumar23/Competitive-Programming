# Children Sum Property in Binary Tree

This project modifies a binary tree to satisfy the **Children Sum Property**.

---

## Problem

For every node of the binary tree, the value of the node should be equal to the sum of its children.  
- If the node is a leaf, no changes are needed.  
- If the sum of children is greater than the node, update the node.  
- Otherwise, update the children recursively to satisfy the property.

---

## Solution

- Recursively traverse the tree.  
- Update nodes or children based on the sum.  
- After recursion, update the root value according to the updated children.  
- Time complexity: O(n), n = number of nodes.

---

## How to Run

1. Clone the repository:

```bash
git clone <your-repo-url>
