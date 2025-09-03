#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution class implementing Lowest Common Ancestor (LCA)
class Solution {
public:
    // Function to find LCA of nodes p and q in binary tree rooted at 'root'
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base cases:
        if (root == NULL || root == p || root == q) {
            return root;
        }

        // Search left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If one node found in left and one in right, root is LCA
        if (left && right) return root;

        // Otherwise return whichever side is non-null
        return (left != NULL) ? left : right;
    }
};

// Helper function to build a sample binary tree
TreeNode* createSampleTree(TreeNode*& p, TreeNode*& q) {
    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Select nodes for LCA test
    p = root->left;              // Node 5
    q = root->left->right->right; // Node 4
    return root;
}

int main() {
    TreeNode* p;
    TreeNode* q;
    TreeNode* root = createSampleTree(p, q);

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca)
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "No common ancestor found." << endl;

    return 0;
}
