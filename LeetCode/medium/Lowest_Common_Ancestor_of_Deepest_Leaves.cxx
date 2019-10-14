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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto res = f(root, 0);
        return res.second;
    }
    
    pair<int, TreeNode*> f(TreeNode* n, int d)
    {
        if (!n)
        {
            return make_pair(-1, nullptr);            
        }
        
        auto l = f(n->left, d+1);
        auto r = f(n->right, d+1);
        
        if (l.first == r.first && l.first > d)
        {
            return make_pair(l.first, n);
        }
        else
        {
            if (l.first > r.first)
                return l;
            else if (r.first > l.first)
                return r;
            else
                return make_pair(d, n);
        }
    }
};