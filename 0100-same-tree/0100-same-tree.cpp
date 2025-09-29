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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> qNodes;
        qNodes.push({p, q});

        while(!qNodes.empty()) {
            auto[node1, node2] = qNodes.front();
            qNodes.pop();

            if(!node1 && !node2) continue;
            if(!node1 || !node2) return false;
            if(node1->val != node2->val) return false;

            qNodes.push({node1->left, node2->left});
            qNodes.push({node1->right, node2->right});
        }
        return true;
    }
};