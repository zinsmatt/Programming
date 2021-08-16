/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    pair<TreeNode*, TreeNode*> solve(TreeNode* n)
    {
        if (n)
        {
            auto* l = n->left;
            auto* r = n->right;
            n->left = nullptr;
            auto [l1, l2] = solve(l);
            auto [r1, r2] = solve(r);
            auto* insert = n;
            auto* end = n;
            if (l1)
            {
                insert->right = l1;
                insert = l2;
                end = l2;
            } 
            if (r1)
            {
                insert->right = r1;
                end = r2;
            }
            return {n, end};
        }
        return {nullptr, nullptr};
    }
public:
    void flatten(TreeNode* root) {
        solve(root);   
    }
};
