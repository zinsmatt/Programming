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
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
    
    TreeNode* invert(TreeNode* n)
    {
        if (n)
        {
            auto *left = invert(n->left);
            auto *right = invert(n->right);
            n->left = right;
            n->right = left;
        }
        return n;
    }
};