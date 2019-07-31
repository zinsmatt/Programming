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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        level(root, res, 0);
        std::reverse(res.begin(), res.end());
        return res;
    }
    
    void level(TreeNode* root, vector<vector<int>>& res, int lvl)
    {
        if (root)
        {
            if (lvl == res.size())
            {
                res.push_back(vector<int>());
            }
            res[lvl].push_back(root->val);
            level(root->left, res, lvl+1);
            level(root->right, res, lvl+1);               
        }
    }
};