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
    
    
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        auto* n = new TreeNode(0);
        if (root1) n->val += root1->val;
        if (root2) n->val += root2->val;
        
        if (!root1)
        {
            n->left = mergeTrees(nullptr, root2->left);
            n->right = mergeTrees(nullptr, root2->right);
        }
        else if (!root2)
        {
            n->left = mergeTrees(root1->left, nullptr);
            n->right = mergeTrees(root1->right, nullptr);
        }
        else
        {
            n->left = mergeTrees(root1->left, root2->left);
            n->right = mergeTrees(root1->right, root2->right);
        }
        return n;        
    }
};
