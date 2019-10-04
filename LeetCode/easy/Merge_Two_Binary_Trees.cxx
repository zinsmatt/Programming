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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return build(t1, t2);
    }
    
    TreeNode* build(TreeNode* a, TreeNode* b)
    {
        if (!a && !b)
            return nullptr;
        else
        {
            int v1 = 0, v2 = 0;
            if (a)
                v1 = a->val;
            if (b)
                v2 = b->val;
            auto* nouv = new TreeNode(v1 + v2);
            if (!a)
            {
                nouv->left = build(nullptr, b->left);
                nouv->right = build(nullptr, b->right);
            }
            else if (!b)
            {
                nouv->left = build(a->left, nullptr);
                nouv->right = build(a->right, nullptr);
            }
            else
            {
                nouv->left = build(a->left, b->left);
                nouv->right = build(a->right, b->right);
            }
            return nouv;
        }
    }
};