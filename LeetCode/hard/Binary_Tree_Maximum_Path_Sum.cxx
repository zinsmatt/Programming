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
    
    int maxi = -numeric_limits<int>::max();
    
    int f(TreeNode* n)
    {
        if (!n) return 0;
        else
        {
            int max_left = 0;
            if (n->left)
            {
                max_left = max(0, f(n->left));
            }
            int max_right = 0;
            if (n->right)
            {
                max_right = max(0, f(n->right));
            }
            maxi = max(maxi, n->val + max_right + max_left);
            return n->val + max(0, max(max_right, max_left));
        }
    }
    
public:
    int maxPathSum(TreeNode* root) {
        f(root);
        return maxi;
    }
};
