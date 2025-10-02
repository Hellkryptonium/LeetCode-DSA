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
    int countFromNode(TreeNode* node, long long target) {
        if (!node) return 0;
        int count = 0;
        if(node->val == target) count++;
        count += countFromNode(node->left, target-node->val);
        count += countFromNode(node->right, target-node->val);
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return countFromNode(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};