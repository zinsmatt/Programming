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
    void solve(TreeNode* n, int l) {
        res = max(res, l);
        if (n) {
            solve(n->left, l+1);
            solve(n->right, l+1);
        }
    }
public:
    int maxDepth(TreeNode* root) {
        solve(root, 0);
        return res;        
    }
};
