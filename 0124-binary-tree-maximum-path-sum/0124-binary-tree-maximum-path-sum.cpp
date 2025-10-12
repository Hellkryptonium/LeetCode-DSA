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
private:
    int dfs(TreeNode* node, int &globalMax) {
        if(!node) return 0;

        int leftSum = max(0, dfs(node->left, globalMax));
        int rightSum = max(0, dfs(node->right, globalMax));

        int throughNode = node->val + leftSum + rightSum;

        globalMax = max(globalMax, throughNode);

        return node->val + max(leftSum, rightSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;
        dfs(root, globalMax);
        return globalMax;
    }
};