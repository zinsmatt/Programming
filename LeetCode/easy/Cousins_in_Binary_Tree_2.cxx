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
    pair<int, int> depth(TreeNode* n, int v, int d, int prev)
    {
        if (!n)
        {
            return {-1, -1};
        }
        if (v == n->val)
        {
            return {d, prev};
        }
        auto r1 = depth(n->left, v, d+1, n->val);
        if (r1.first != -1) return r1;
        auto r2 = depth(n->right, v, d+1, n->val);
        return r2;
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        auto [d1, p1] = depth(root, x, 0, -1);
        auto [d2, p2] = depth(root, y, 0, -1);
        return d1 == d2 && p1 != p2;
    }
};
