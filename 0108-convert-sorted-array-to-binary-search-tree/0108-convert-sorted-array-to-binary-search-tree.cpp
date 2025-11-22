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
    TreeNode* build(vector<int>& nums, int i, int j) {
        if(i > j) return nullptr;
        
        int mid = i + (j-i)/2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = build(nums,i,mid-1);
        root->right = build(nums,mid+1,j);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return build(nums,0,nums.size()-1);
    }
};