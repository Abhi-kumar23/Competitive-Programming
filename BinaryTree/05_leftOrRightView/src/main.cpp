#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
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
    // Function to return the right side view of a binary tree
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        
        vector<TreeNode*> q;
        q.push_back(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q[0];
                q.erase(q.begin());

                // Capture last node of this level
                if (i == n - 1) ans.push_back(node->val);

                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
        }
        return ans;
    }
};

// Sample usage
int main() {
    /*
            1
           / \
          2   3
           \    \
            5    4
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> view = sol.rightSideView(root);

    cout << "Right Side View: ";
    for (int val : view) cout << val << " ";
    cout << endl;

    return 0;
}
