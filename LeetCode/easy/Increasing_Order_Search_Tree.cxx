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
    std::pair<TreeNode*, TreeNode*> solve(TreeNode* n) {
        if (!n) return  {nullptr, nullptr};
        
        
        TreeNode* first = nullptr, *end = nullptr;
        auto left = solve(n->left);
        auto right = solve(n->right);
        
        
        if (left.first)
        {
            first = left.first;
            left.second->right = n;
        }
        else
        {
            first = n;
        }
        end = n;
        end->left = nullptr;
        end->right = nullptr;
        
        
        
        if (right.first)
        {
            end->right = right.first;
            end = right.second;
        }
        
        return {first, end};            
    }
    
    
    TreeNode* increasingBST(TreeNode* root) {
        auto res = solve(root);
        return res.first;
    }
};
