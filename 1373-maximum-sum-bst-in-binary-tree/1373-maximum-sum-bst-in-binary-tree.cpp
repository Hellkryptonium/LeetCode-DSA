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
 
class nodeValue {
public:
    int min;
    int max;
    int sum;
    nodeValue(int min, int max, int sum) {
        this->min = min;
        this->max = max;
        this->sum = sum;
    }
};
class Solution {
public:
    int ans = 0;

    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }

    nodeValue helper(TreeNode* root) {
        if(root == nullptr) {
            return nodeValue(INT_MAX, INT_MIN, 0);
        }

        nodeValue left = helper(root->left);
        nodeValue right = helper(root->right);

        if(root->val > left.max && root->val < right.min) {
            int currSum = root->val + left.sum + right.sum;
            ans = max(ans, currSum);

            return nodeValue(
                min(root->val, left.min),
                max(root->val, right.max),
                currSum
            );
        }

        return nodeValue(INT_MIN, INT_MAX, max(left.sum, right.sum));
    }
};