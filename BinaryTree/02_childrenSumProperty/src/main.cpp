#include <iostream>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to change the tree to satisfy the children sum property
    void changeTree(TreeNode* root) {
        if (!root) return;

        int child = 0;
        if (root->left) child += root->left->val;
        if (root->right) child += root->right->val;

        // If child sum >= root, update root
        if (child >= root->val) {
            root->val = child;
        } else { // Else, update children to root value
            if (root->left) root->left->val = root->val;
            if (root->right) root->right->val = root->val;
        }

        // Recursively fix left and right subtrees
        changeTree(root->left);
        changeTree(root->right);

        // Update root value after recursion
        int tot = 0;
        if (root->left) tot += root->left->val;
        if (root->right) tot += root->right->val;
        if (root->left || root->right) root->val = tot;
    }

    // Inorder traversal to print the tree
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
};

// Helper function to create a sample tree
TreeNode* createSampleTree() {
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(2, node4, node5);

    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node3 = new TreeNode(3, node6, node7);

    TreeNode* root = new TreeNode(10, node2, node3);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    Solution sol;

    cout << "Inorder before change: ";
    sol.inorder(root);
    cout << endl;

    sol.changeTree(root);

    cout << "Inorder after change: ";
    sol.inorder(root);
    cout << endl;

    // Cleanup memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
