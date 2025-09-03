# Right Side View of Binary Tree

C++ implementation to return the **nodes visible from the right side** of a binary tree.

---

## Approach

- **Brute Force:**  
  For each node, check if it is the rightmost at its level using DFS.  
  - Time: O(n²) in worst case  
  - Space: O(h)

- **Better:**  
  Use BFS (level-order) and store all nodes at each level, then pick the last.  
  - Time: O(n)  
  - Space: O(n)

- **Optimal (Implemented):**  
  BFS traversal with queue. For each level, capture only the last node directly.  
  - Time: O(n)  
  - Space: O(n)

---

## Complexity
- **Time:** O(n), where n = number of nodes  
- **Space:** O(n) for queue  

---
