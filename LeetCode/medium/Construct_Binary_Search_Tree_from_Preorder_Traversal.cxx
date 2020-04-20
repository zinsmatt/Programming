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
    
    void build(TreeNode* n, int x)
    {
        if (n->val > x)
        {
            if (n->left)
            {
                build(n->left, x);
            }
            else
            {
                n->left = new TreeNode(x);
            }
        }
        else
        {
            if (n->right)
            {
                build(n->right, x);
            }
            else
            {
                n->right = new TreeNode(x);
            }
        }
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder.front());
        for (int i = 1; i < preorder.size(); ++i)
        {
            build(root, preorder[i]);
        }
        return root;        
    }
};
