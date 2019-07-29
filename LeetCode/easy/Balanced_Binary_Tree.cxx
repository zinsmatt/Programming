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
    bool isBalanced(TreeNode* root) {
        auto res = check(root);
        return res.first;
    }
    std::pair<bool, int> check(TreeNode* root)
    {
        if (root)
        {
            auto a = check(root->left);
            auto b = check(root->right);
            bool res = std::abs(a.second - b.second) <= 1 && a.first && b.first;
            return std::make_pair(res, std::max(a.second, b.second) + 1);
        }
        else
        {
            return std::make_pair(true, 0);
        }
    }
};