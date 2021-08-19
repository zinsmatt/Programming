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
    unsigned long long res, total;
    
    unsigned long long solve(TreeNode* n, bool update)
    {
        if (!n)
            return 0;
        auto s = n->val;
        s += solve(n->left, update);
        s += solve(n->right, update);
        if (update)
            res = std::max(res, (total-s)*s);
        return s;
    }
public:
    int maxProduct(TreeNode* root) {
        res = 0;
        total = 0;
        total = solve(root, false);
        solve(root, true);
        
        return res % 1000000007ull;
    }
};
