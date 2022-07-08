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
    void solve(TreeNode *n, int p, int gp) {
        if (!n) return;
        if (gp % 2 == 0 && gp != -1) res += n->val;
        gp = p;
        p = n->val;
        solve(n->left, p, gp);
        solve(n->right, p, gp);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        solve(root, -1, -1);
        return res;
    }
};
