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
        auto v = root->val;

        if (p->val == v || q->val == v)
            return root;
        
        if (p->val < v && q->val < v)
            return lowestCommonAncestor(root->left, p, q);
        else if (p->val > v && q->val > v)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};
