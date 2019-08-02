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
    int maxDepth(TreeNode* root) {
        return maxDepth(root, 0);
    }
    
    int maxDepth(TreeNode* root, int h)
    {
        if (!root)
            return h;
        else
        {
            
            return max(h, max(maxDepth(root->left, h+1), maxDepth(root->right, h+1)));
        }
    }
};