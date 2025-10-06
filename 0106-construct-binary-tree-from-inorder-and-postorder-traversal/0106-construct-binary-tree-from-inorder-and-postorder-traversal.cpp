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
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int,int>& inMap) {

        if(inStart > inEnd || postStart > postEnd) return nullptr;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIndex = inMap[rootVal];
        int leftTreeSize = inRootIndex - inStart;

        root->left = buildTreeHelper(inorder, postorder, inStart, inRootIndex-1, postStart, postStart+leftTreeSize-1, inMap);

        root->right = buildTreeHelper(inorder, postorder, inRootIndex+1, inEnd, postStart+leftTreeSize, postEnd-1, inMap);

        return root; 
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, inMap);
    }
};