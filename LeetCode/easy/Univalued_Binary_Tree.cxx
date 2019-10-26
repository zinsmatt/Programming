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
    bool isUnivalTree(TreeNode* root) {
        if (!root)
            return true;
        else
        {
            return f(root, root->val);
        }
    }
    
    bool f(TreeNode* n, int v)
    {
        if (n)
        {
            return n->val == v && f(n->left, v) && f(n->right, v);
        }
        return true;
    }
};