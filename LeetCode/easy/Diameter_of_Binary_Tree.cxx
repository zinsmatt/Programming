/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


pair<int, int> f(TreeNode* r)
{
    if (r)
    {
        auto left = f(r->left);
        auto right = f(r->right);
        
        auto max_length = left.first + right.first;
        auto max_diam = max(max_length, max(left.second, right.second));
        
        return {max(left.first, right.first)+1, max_diam};     
    }
    else
    {
        return {0, 0};
    }
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        auto res = f(root);
        return res.second;
    }
};
