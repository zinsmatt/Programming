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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        auto* p = parent(root, val);
        auto* nouv = new TreeNode(val);
        if (p)
        {
            if (val < p->val)
                p->left = nouv;
            else
                p->right = nouv;
            return root;
        }
        else
            return nouv;
    }
    
    TreeNode* parent(TreeNode* n, int v)
    {
        if (n)
        {
            if (n->val > v)
            {
                if (n->left)
                    return parent(n->left, v);
                else
                    return n;                
            }
            else
            {
                if (n->right)
                    return parent(n->right, v);
                else
                    return n;
            }
        }
        return nullptr;
    }
};
