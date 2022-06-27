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
    pair<int, bool> solve(TreeNode *n) {
        if (!n) 
            return {0, true};
        
        auto [hl, sl] = solve(n->left);
        auto [hr, sr] = solve(n->right);
        
        return {std::max(hl, hr) + 1, sl && sr && std::abs(hl - hr) <= 1};
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root).second;
    }
};
