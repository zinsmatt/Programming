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
    TreeNode* bstToGst(TreeNode* root) {
        solve(root, 0);
        return root;
    }
    
    int solve(TreeNode* n, int cur)
    {
        if (n)
        {
            auto r = solve(n->right, cur);
            n->val = n->val + r;
            auto l = solve(n->left, n->val);
            return l;        
        }
        return cur;
    }
};
