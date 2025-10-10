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
 
        queue<pair<TreeNode*, int>> q;
        q.push({root, targetSum-root->val});

        while(!q.empty()) {
            auto[node, currSum] = q.front();
            q.pop();

            if(!node->left && !node->right && currSum == 0) {
                return true;
            }

            if(node->left) q.push({node->left, currSum-node->left->val});

            if(node->right) q.push({node->right, currSum-node->right->val});
        }
        return false;
    }
};