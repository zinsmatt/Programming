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
    vector<int> res;
    void preorder(TreeNode* n) {
        if (n) {
            res.push_back(n->val);
            preorder(n->left);
            preorder(n->right);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res;
    }
};
