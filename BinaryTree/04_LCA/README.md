# Lowest Common Ancestor (LCA) in a Binary Tree

C++ implementation of Lowest Common Ancestor (LCA) in a Binary Tree.

---

## Approach

- **Brute Force:**  
  Store paths from root to both nodes, then compare.  
  - Time: O(n)  
  - Space: O(n)

- **Better:**  
  Use parent pointers and hash set to find first common ancestor.  
  - Time: O(n)  
  - Space: O(n)

- **Optimal (Implemented):**  
  Recursive DFS.  
  - If current node is `p` or `q`, return it.  
  - Recurse left and right.  
  - If both return non-null → current node is LCA.  
  - Time: O(n)  
  - Space: O(h), where h = height of tree

---

## Example

For the following tree:
```
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4
```