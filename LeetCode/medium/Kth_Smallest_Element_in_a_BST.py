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
    int res = -1;
    int count = 0;
    int solve(TreeNode *n, int k)
    {
        if (!n)
            return 0;
        
        solve(n->left, k);
        count++;
        if (count == k)
        {
            res = n->val;
        }
        solve(n->right, k);
        
        return 0;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        solve(root, k);
        return res;
    }
};
