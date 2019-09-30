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
    TreeNode* searchBST(TreeNode* root, int val) {
        return find(root, val);
    }
    
    TreeNode* find(TreeNode* n, int v)
    {
        if (n)
        {
            if (n->val == v)
                return n;
            else if (n->val > v)
                return find(n->left, v);
            else
                return find(n->right, v);
        }
        return nullptr;
    }
};