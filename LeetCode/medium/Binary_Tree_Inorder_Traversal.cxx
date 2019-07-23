/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }
    
    void traverse(TreeNode* n, vector<int>& res)
    {
        if (n)
        {
            traverse(n->left, res);
            res.push_back(n->val);
            traverse(n->right, res);
        }
    }
};