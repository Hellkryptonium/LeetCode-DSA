/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        stack<TreeNode*> st;
        parent[root] = nullptr;
        st.push(root);

        while(parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            TreeNode* node = st.top();
            st.pop();

            if(node->left) {
                parent[node->left] = node;
                st.push(node->left);
            }

            if(node->right) {
                parent[node->right] = node;
                st.push(node->right);
            }
        }

        unordered_set<TreeNode*> ancestor;
        while(p != nullptr) {
            ancestor.insert(p);
            p = parent[p];
        }

        while(ancestor.find(q) == ancestor.end()) {
            q = parent[q];
        }

        return q;
    }
};