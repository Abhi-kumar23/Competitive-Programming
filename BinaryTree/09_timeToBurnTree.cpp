#include<iostream>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

class solution{
    public:
    int timeToBurnTree(TreeNode* root, int start){
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;
        TreeNode* target;
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) target = node;
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int time = 0;
        
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left && !visited[node->left]){
                    flag = true;
                    visited[node->left] = true;
                    q.push(node->left);
                }
                
                if(node->right && !visited[node->right]){
                    flag = true;
                    visited[node->right] = true;
                    q.push(node->right);
                }
                
                if(parent[node] && !visited[parent[node]]){
                    flag = true;
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
            if(flag) time++;
        }
        
        return time;
    }
};