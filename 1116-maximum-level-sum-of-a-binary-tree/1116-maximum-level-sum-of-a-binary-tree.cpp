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
    void dfs(TreeNode* node, int level, vector<int>& sums) {
        if(!node) return;

        if(sums.size() < level) {
            sums.push_back(0);
        }

        sums[level-1] += node->val;

        dfs(node->left, level+1, sums);
        dfs(node->right, level+1, sums);
    }
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> levelSums;
        dfs(root, 1, levelSums);

        int maxSum = INT_MIN;
        int resultLevel = 1;

        for(int i=0; i<levelSums.size(); i++) {
            if(levelSums[i] > maxSum) {
                maxSum = levelSums[i];
                resultLevel = i + 1;
            }
        }
        return resultLevel;
    }
};