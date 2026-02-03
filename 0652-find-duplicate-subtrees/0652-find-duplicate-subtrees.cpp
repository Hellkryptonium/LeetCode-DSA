class Solution {
public:
    unordered_map<string, int> freq;
    vector<TreeNode*> ans;

    string dfs(TreeNode* root) {
        if (!root) return "#";

        string left = dfs(root->left);
        string right = dfs(root->right);

        string serial = to_string(root->val) + "," + left + "," + right;

        if (++freq[serial] == 2) {
            ans.push_back(root);
        }

        return serial;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
