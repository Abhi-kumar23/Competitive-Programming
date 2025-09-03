#include <iostream>
#include <cmath>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if (lh == rh) return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int findLeftHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->left;
        }
        return height;
    }

    int findRightHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->right;
        }
        return height;
    }
};

// Helper function to create a sample binary tree
TreeNode* createSampleTree() {
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(3, node6, node7);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* root = new TreeNode(1, node2, node3);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    Solution sol;

    cout << "Number of nodes in the complete binary tree: " << sol.countNodes(root) << endl;

    // Cleanup dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
