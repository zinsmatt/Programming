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
    int max_l = 0;
    int s = 0;
    void solve(TreeNode *n, int l)
    {
        if (!n) return ;
        
        if (!n->right && !n->left) {
            if (l > max_l) {
                max_l = l;
                s = n->val;
            } else if (l == max_l) {
                s += n->val;
            }
        }
        
        solve(n->left, l+1);
        solve(n->right, l+1);
    }

    
public:
    int deepestLeavesSum(TreeNode* root) {
        solve(root, 0);
        return s;
    }
};
