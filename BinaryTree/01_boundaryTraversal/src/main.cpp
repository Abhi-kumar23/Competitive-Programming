#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    Node(int data, Node* left, Node* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Solution {
public:
    // Check if a node is a leaf node
    bool isLeaf(Node* node) {
        return !node->left && !node->right;
    }

    // Add left boundary nodes (excluding leaf nodes)
    void leftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    // Add right boundary nodes (excluding leaf nodes) in reverse order
    void rightBoundary(Node* root, vector<int>& res) {
        Node* curr = root->right;
        vector<int> temp;
        while (curr) {
            if (!isLeaf(curr)) temp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

    // Add all leaf nodes in left-to-right order
    void addLeaves(Node* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }

    // Perform boundary traversal of the binary tree
    vector<int> boundaryTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data); // Include root if it's not a leaf
        leftBoundary(root, res);
        addLeaves(root, res);
        rightBoundary(root, res);
        return res;
    }
};

// Helper function to create a sample binary tree
Node* createSampleTree() {
    Node* node7 = new Node(7);
    Node* node6 = new Node(6);
    Node* node5 = new Node(5);
    Node* node4 = new Node(4);
    Node* node3 = new Node(3, node6, node7);
    Node* node2 = new Node(2, node4, node5);
    Node* root = new Node(1, node2, node3);
    return root;
}

int main() {
    Node* root = createSampleTree();
    Solution sol;

    vector<int> boundary = sol.boundaryTraversal(root);

    cout << "Boundary traversal of the binary tree: ";
    for (int val : boundary) {
        cout << val << " ";
    }
    cout << endl;

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
