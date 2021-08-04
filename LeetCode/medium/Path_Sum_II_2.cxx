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
    vector<vector<int>> res;
    
    void solve(TreeNode* n, int target, vector<int> cur)
    {
        if (!n) return;
        cur.push_back(n->val);
        target-= n->val;
        if (n->left)
        {
            solve(n->left, target, cur);
        }
        if (n->right)
        {
            solve(n->right, target, cur);
        }
        if (!n->left && !n->right)
        {
            if (target == 0)
            {
                res.push_back(cur);
            }
        }
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum, {});
        return res;        
    }
};
