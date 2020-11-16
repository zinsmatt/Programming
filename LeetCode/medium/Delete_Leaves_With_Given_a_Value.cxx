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
    TreeNode* solve(TreeNode* n, int target) {
        if (!n) return n;
        else
        {
            auto *l = solve(n->left, target);
            auto *r = solve(n->right, target);
            n->left = l;
            n->right = r;
            if (!r && !l && n->val == target) 
                return nullptr;
            else
                return n;
        }
        
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root, target);   
    }
};
