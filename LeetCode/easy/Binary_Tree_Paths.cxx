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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        f(root, "", res);
        return res;
    }
    void f(TreeNode* n, string cur, vector<string>& res)
    {
        if (n)
        {
            cur += std::to_string(n->val);
            if (!n->left && !n->right)
            {
                res.push_back(cur);
            }
            else
            {
                cur += "->";
                f(n->left, cur, res);
                f(n->right, cur, res);
            }
        }
    }
};