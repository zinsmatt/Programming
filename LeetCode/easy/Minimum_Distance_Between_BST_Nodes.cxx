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
    int prev = -1000000;
    int res = std::numeric_limits<int>::max();

    void solve(TreeNode *n) {
        if (n) {
            solve(n->left);
            res = min(res, abs(prev-n->val));
            prev = n->val;
            solve(n->right);
        }
    }
public:
    int minDiffInBST(TreeNode* root) {
        solve(root);
        return res;
    }
};
