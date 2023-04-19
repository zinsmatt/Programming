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
public:

    void solve(TreeNode* n, int prev, int coming) {
        res = max(res, prev);
        if (n) {
            if (n->left) {
                if (coming == 0)
                    solve(n->left, 1, 0);
                else
                    solve(n->left, prev+1, 0);
            }
            if (n->right) {
                if (coming == 0)
                    solve(n->right, prev+1, 1);
                else
                    solve(n->right, 1, 1);
            }
        }
    }

    int longestZigZag(TreeNode* root) {
        solve(root, 0, 0);
        return res;
        
    }
};
