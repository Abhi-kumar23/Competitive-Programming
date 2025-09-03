#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class solution {
public: 
    void leftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

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

    void addLeaves(Node* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }

    bool isLeaf(Node* node) {
        return !node->left && !node->right;
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);
        leftBoundary(root, res);
        addLeaves(root, res);
        rightBoundary(root, res);
        return res;
    }
}