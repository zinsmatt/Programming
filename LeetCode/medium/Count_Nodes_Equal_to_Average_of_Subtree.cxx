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
    int res = 0;
    
    pair<int, int> solve(TreeNode *n)
    {
        if (!n) 
            return {0, 0};
        auto [nl, l] = solve(n->left);
        auto [nr, r] = solve(n->right);
        int s = n->val + l + r;
        
        auto m = s / (1 + nl + nr);
        res += m == n->val;
        return {1 + nl + nr, s};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return res;
    }
};
