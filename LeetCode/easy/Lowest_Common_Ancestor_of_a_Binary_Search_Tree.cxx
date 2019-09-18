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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root, p->val, q->val);
    }
    
    TreeNode* f(TreeNode* n, int p, int q)
    {
        if (n)
        {
            if (n->val == p || n->val == q)
                return n;
            else
            {
                if (n->val > p && n->val < q ||
                    n->val < p && n->val > q)
                {
                    return n;
                }
                else
                {
                    if (n->val < p)
                    {
                        return f(n->right, p, q);
                    }
                    else
                        return f(n->left, p, q);
                }
            }
        }
        return  nullptr;
    }
};