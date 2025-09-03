#include<iostream>
using namespace std;

//Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class solution{
public: 
    vector<vector<int>> verticalTraversal(TreeNode* root){
        map<int, map<int, multiset<int>>>nodes;
        queue < pair < TreeNode*, pair<int,int>>> todo;
        todo.push({root},{0,0});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.front();
            int x = p.second.first(), y = p.second.second();
            node[x][y].insert(node->val);
            if(node -> left){
                todo.push({node->left},{x + 1,y - 1});
            }
            if(node->right){
                todo.push({node->right}, {row+1, col+1});
            }
        }
        vector<vector<int>>ans;
        for(auto p : nodes){
            vector<int>col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // (column, row, value)
        map<int, map<int, multiset<int>>> nodes;
        
        // Queue stores: node, column, row
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});
        
        while(!q.empty()){
            auto [node, pos] = q.front();
            q.pop();
            
            int col = pos.first;
            int row = pos.second;
            
            nodes[col][row].insert(node->val);
            
            if(node->left) 
                q.push({node->left, {col-1, row+1}});
            if(node->right) 
                q.push({node->right, {col+1, row+1}});
        }
        
        vector<vector<int>> result;
        for(auto &col : nodes){
            vector<int> colVals;
            for(auto &row : col.second){
                colVals.insert(colVals.end(), row.second.begin(), row.second.end());
            }
            result.push_back(colVals);
        }
        
        return result;
    }
};