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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);        

    }
    
    bool check(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
            return true;
        else if (a && b)
        {
            return a->val == b->val && check(a->left, b->left) && check(a->right, b->right);
        }
        else
            return false;
    }
    
};