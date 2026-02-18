class Solution {
public:
    vector<string> ans;

    void dfs(TreeNode* node, string path) {
        if (!node) return;

        // Add current node to path
        path += to_string(node->val);

        // If leaf node → store result
        if (!node->left && !node->right) {
            ans.push_back(path);
            return;
        }

        // Not a leaf → keep going
        path += "->";

        dfs(node->left, path);
        dfs(node->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};
