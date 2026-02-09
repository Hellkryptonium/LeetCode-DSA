class Solution {
public:
    vector<int> inorder;

    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);
        return buildBalancedBST(0, inorder.size() - 1);
    }

private:
    void inorderTraversal(TreeNode* root) {
        if (!root) return;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }

    TreeNode* buildBalancedBST(int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root->left = buildBalancedBST(left, mid - 1);
        root->right = buildBalancedBST(mid + 1, right);

        return root;
    }
};
