// Recursive Solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
    
private:
    void preorder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        res.push_back(node->val);          // visit root
        preorder(node->left, res);         // left
        preorder(node->right, res);        // right
    }
};

// Iterative Solution (using stack)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            res.push_back(node->val);

            if (node->right) st.push(node->right);  // push right first
            if (node->left) st.push(node->left);    // then left
        }

        return res;
    }
};

// Morris Preorder Traversal (Optimal)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                res.push_back(curr->val);  // visit root
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    res.push_back(curr->val);   // visit root before going left
                    pred->right = curr;         // make thread
                    curr = curr->left;
                } else {
                    pred->right = nullptr;      // remove thread
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};

