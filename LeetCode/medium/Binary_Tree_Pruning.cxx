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
    TreeNode* solve(TreeNode* n) {
        if (!n)
            return n;
        else
        {
            auto* l = solve(n->left);
            auto* r = solve(n->right);
            n->left = l;
            n->right = r;
            if (l || r)
                return n;
            else {
                if (n->val)
                    return n;
                else
                    return nullptr;
            }
        }
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        return solve(root);        
    }
};
