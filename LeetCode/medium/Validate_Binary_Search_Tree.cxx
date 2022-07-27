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
	tuple<bool, long, long> solve(TreeNode* n) 
    {
        if (!n)
            return {true, std::numeric_limits<long>::max(), std::numeric_limits<long>::min()};
        auto [l, lmin, lmax] = solve(n->left);
        auto [r, rmin, rmax] = solve(n->right);
        bool ok = r && l && n->val > lmax && n->val < rmin;
        return {ok, std::min((long)n->val, std::min(lmin, rmin)), std::max((long)n->val, std::max(lmax, rmax))};
    }

public:
    bool isValidBST(TreeNode* root) {
        if (!root) 
            return true;
        auto [res, min, max] = solve(root);
        return res;        
    }
};

