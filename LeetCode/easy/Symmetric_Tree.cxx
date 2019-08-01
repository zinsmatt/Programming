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
    bool isSymmetric(TreeNode* root) {
       if (!root)
           return true;
        else
            return check(root->left, root->right);
    }
    
    bool check(TreeNode *l, TreeNode *r)
    {
        if (!l && !r)
            return true;
        else if (l && r)
        {
            return l->val == r->val && check(l->left, r->right) && check(l->right, r->left);
        }
        else
            return false;
    }
};