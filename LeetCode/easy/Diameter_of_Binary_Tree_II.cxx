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
    int diameter = 0;
    int find_diameter(TreeNode* n) {
        if (!n) return 0;
        auto l = find_diameter(n->left);
        auto r = find_diameter(n->right);
        diameter = std::max(diameter, l+r);
        return 1 + std::max(l, r);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        find_diameter(root);
        return diameter;
        
    }
};
