#include<iostream>
using namespace std;

class solution {
public:
    vector<int> preIntPostTraversal(Node* root){
        stack<pair<Node*, int>> st;
        vector<int> pre, in, post;
        if (root == NULL) return { };
        st.push({root, 1});
        while (!st.empty()) {
            auto it = st.top();
            st.pop();
            Node* node = it.first;
            int state = it.second;

            if (state == 1) {
                pre.push_back(node->data);
                it.second++;
                st.push(it);
                if (node->left) {
                    st.push({node->left, 1});
                }
            } else if (state == 2) {
                in.push_back(node->data);
                it.second++;
                st.push(it);
                if (node->right) {
                    st.push({node->right, 1});
                }
            } else {
                post.push_back(node->data);
            }
        }
        return {pre, in, post};
    }