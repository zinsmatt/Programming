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
    vector<int> pre;
public:
    void preorder(TreeNode* root) {
        if (root)
        {
            pre.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        pre.clear();
        preorder(root);
        return pre;
    }
};
