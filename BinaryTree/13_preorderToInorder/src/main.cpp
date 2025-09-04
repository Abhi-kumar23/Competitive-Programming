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