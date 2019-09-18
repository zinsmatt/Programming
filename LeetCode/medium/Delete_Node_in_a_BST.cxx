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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        auto* n = root;
        TreeNode* prev = nullptr;
        while (n && n->val != key)
        {
            prev = n;
            if (n->val > key)
            {
                n = n->left;
            }
            else
                n = n->right;
        }
        
        if (n)
        {
            auto* l = n->left;
            auto* r = n->right;
            
            if (!prev || prev->left == n)
            {
                if (r)
                {
                    auto *rl = r;
                    while (rl && rl->left)
                        rl = rl->left;
                    rl->left = l;
                    if (prev)
                        prev->left = r;
                    else
                        return r;
                }
                else
                {
                    if (prev)
                        prev->left = l;
                    else
                        return l;
                }               
            }
            else
            {
                if (l)
                {
                    auto *lr = l;
                    while (lr && lr->right)
                        lr = lr->right;
                    lr->right = r;
                    prev->right = l;
                }
                else
                    prev->right = r;
            }
        }
        return root;
    }
    
};