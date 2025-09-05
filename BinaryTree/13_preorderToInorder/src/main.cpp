#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
}

TreeNode* buildTree(int* preorder, int* inorder, int inStart, int inEnd, int& preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    TreeNode* node = new TreeNode(preorder[preIndex++]);

    if (inStart == inEnd) {
        return node;
    }

    int inIndex;
    for (inIndex = inStart; inIndex <= inEnd; inIndex++) {
        if (inorder[inIndex] == node->val) {
            break;
        }
    }

    node->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return node;
}

TreeNode* buildTree(int* preorder, int* inorder, int size) {
    int preIndex = 0;
    return buildTree(preorder, inorder, 0, size - 1, preIndex);
}

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         map<int,int>inMap;
//         for(int i = 0; i < inorder.size(); i++) {
//             inMap[inorder[i]] = i;  
//         }

//         TreeNode* root = buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, inMap);
//         return root;
//     }
//     TreeNode* buildTree(vector<int>&preorder,vector<int>&inorder,int preStart, int preEnd, int inStart, int inEnd, map<int,int>&inMap){
//         if(preStart > preEnd || inStart > inEnd) return NULL;

//         TreeNode* root = new TreeNode(preorder[preStart]);

//         int inRoot = inMap[root -> val];
//         int leftStart = inRoot - inStart;

//         root -> left = buildTree(preorder, inorder, preStart + 1, preStart + leftStart, inStart, inRoot - 1, inMap);
//         root -> right = buildTree(preorder, inorder, preStart+ leftStart + 1, preEnd, inRoot + 1, inEnd, inMap);

//         return root;
//     }
// };