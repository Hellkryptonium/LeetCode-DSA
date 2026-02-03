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
    void dfs(TreeNode* root, int &ans, int low, int high) {
        if(root == nullptr) return;

        if(root->val <= high && root->val >= low) {
            ans += root->val;
        }

        if(root->val > low) {
            dfs(root->left, ans, low, high);
        }
        if(root->val < high) {
            dfs(root->right, ans, low, high);
        }  
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        dfs(root, ans, low, high);
        return ans;
    }
};