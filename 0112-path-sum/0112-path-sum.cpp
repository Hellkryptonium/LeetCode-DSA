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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
 
        stack<pair<TreeNode*, int>> st;
        st.push({root, targetSum-root->val});

        while(!st.empty()) {
            auto[node, currSum] = st.top();
            st.pop();

            if(!node->left && !node->right && currSum == 0) {
                return true;
            }

            if(node->left) st.push({node->left, currSum-node->left->val});

            if(node->right) st.push({node->right, currSum-node->right->val});
        }
        return false;
    }
};