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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;

        int totalSum = 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});

        while(!st.empty()) {
            auto[node, currentSum] = st.top();
            st.pop();

            if(!node->left && !node->right) {
                totalSum += currentSum;
            }

            if(node->left) st.push({node->left, currentSum*10 + node->left->val});
            if(node->right) st.push({node->right, currentSum*10 + node->right->val});
        }
        return totalSum;
    }
};