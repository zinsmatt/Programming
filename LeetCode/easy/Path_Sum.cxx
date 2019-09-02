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
    bool hasPathSum(TreeNode* root, int sum) {
        return check(root, sum, 0);
    }
    
    bool check(TreeNode* root, int s, int c)
    {
        if (root)
        {
            c += root->val;
            if (!root->left && !root->right)
            {
                return c  == s;
            }
            else
            {
                return check(root->left, s, c) || check(root->right, s, c);
            }
        }
        return false;
    }
};