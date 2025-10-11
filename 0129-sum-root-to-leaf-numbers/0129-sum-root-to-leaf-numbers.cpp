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
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while(!q.empty()) {
            auto[node, currentSum] = q.front();
            q.pop();

            if(!node->left && !node->right) {
                totalSum += currentSum;
            }

            if(node->left) q.push({node->left, currentSum*10 + node->left->val});
            if(node->right) q.push({node->right, currentSum*10 + node->right->val});
        }
        return totalSum;
    }
};