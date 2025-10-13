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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;

        if(root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }

        if(root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        if(!root->left) {
            return root->right;
        }

        if(!root->right) {
            return root->left;
        }

        TreeNode* succ = root->right;
        while(succ -> left) {
            succ = succ -> left;
        }
        succ -> left = root->left;
        root = root->right;

        return root;
    }
};