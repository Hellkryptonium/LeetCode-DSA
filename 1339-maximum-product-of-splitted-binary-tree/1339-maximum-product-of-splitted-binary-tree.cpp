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
    int treeSum(TreeNode* root, vector<int>& allSum) {
        if(root == nullptr) return 0;

        int leftSum = treeSum(root->left, allSum);
        int rightSum = treeSum(root->right, allSum);
        int sum = root->val + leftSum + rightSum;
        allSum.push_back(sum);
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        constexpr long kMod = 1'000'000'007;
        vector<int> allSum;
        long ans = 0;
        long totalSum = treeSum(root, allSum);

        for(const long sum : allSum) {
            ans = max(ans, sum * (totalSum - sum));
        }

        return ans % kMod;
    }
};