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

    void solve(TreeNode *n) {
        if (n) {
            solve(n->left);
            solve(n->right);
            swap(n->left, n->right);
        }
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};
