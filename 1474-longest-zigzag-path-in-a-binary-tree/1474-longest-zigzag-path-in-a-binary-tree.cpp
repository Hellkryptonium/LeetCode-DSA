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
    int maxZigZag = 0;

    void dfs(TreeNode* node, bool isLeft, int length) {
        if(!node) return;

        maxZigZag = max(maxZigZag, length);

        if(isLeft) {
            dfs(node->left, false, length+1);
            dfs(node->right, true, 1);
        } else {
            dfs(node->right, true, length+1);
            dfs(node->left, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        dfs(root->left, false, 1);
        dfs(root->right, true, 1);
        return maxZigZag;
    }
};