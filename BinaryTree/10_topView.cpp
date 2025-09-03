#include<iostream>
using namsespace std;

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
    vector<int> topView(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        map<int, int> mp; // horizontal distance, node value
        queue<pair<Node*, int>> q; // node, horizontal distance
        q.push({root, 0});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int hd = it.second;
            if (mp.find(hd) == mp.end()) {
                mp[hd] = node->data;
            }
            if (node->left) {
                q.push({node->left, hd - 1});
            }
            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }   
};