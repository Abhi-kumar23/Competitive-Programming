#include <iostream>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Check if a tree is symmetric
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

private:
    // Helper function to check if two subtrees are mirrors of each other
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;           // Both null
        if (!left || !right) return false;          // One null
        if (left->val != right->val) return false;  // Values mismatch

        // Recursively check mirror property
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};

// Helper function to create a sample symmetric tree
TreeNode* createSymmetricTree() {
    TreeNode* node4_left = new TreeNode(4);
    TreeNode* node5_left = new TreeNode(5);
    TreeNode* node2_left = new TreeNode(2, node4_left, node5_left);

    TreeNode* node5_right = new TreeNode(5);
    TreeNode* node4_right = new TreeNode(4);
    TreeNode* node2_right = new TreeNode(2, node5_right, node4_right);

    TreeNode* root = new TreeNode(1, node2_left, node2_right);
    return root;
}

int main() {
    TreeNode* root = createSymmetricTree();
    Solution sol;

    if (sol.isSymmetric(root))
        cout << "The tree is symmetric." << endl;
    else
        cout << "The tree is not symmetric." << endl;

    // Cleanup dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}