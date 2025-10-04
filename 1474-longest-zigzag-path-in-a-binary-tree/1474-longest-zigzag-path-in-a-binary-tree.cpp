/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        int maxZigZag = 0;
        stack<tuple<TreeNode*, bool, int>> st;

        if(root->left) st.push({root->left, true, 1});
        if(root->right) st.push({root->right, false, 1});

        while(!st.empty()) {
            auto [node, isLeft, length] = st.top();
            st.pop();
            
            maxZigZag = max(maxZigZag, length);

            if(isLeft) {
                if(node->right) st.push({node->right, false, length+1});
                if(node->left) st.push({node->left, true, 1});
            } else {
                if(node->left) st.push({node->left, true, length+1});
                if(node->right) st.push({node->right, false, 1});
            }
        }
        return maxZigZag;
    }
};