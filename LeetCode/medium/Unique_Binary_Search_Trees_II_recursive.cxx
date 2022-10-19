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
    TreeNode* deep_copy(TreeNode* n) {
        if (!n)
            return nullptr;
        TreeNode* nouv = new TreeNode(n->val);
        nouv->left = deep_copy(n->left);
        nouv->right = deep_copy(n->right);
        return nouv;
    }
   

    vector<TreeNode*> build(int a, int b) {
        if (a > b)
            return {nullptr};
        if (a == b)
            return {new TreeNode(a)};
        vector<TreeNode*> res;
        for (int root = a; root <= b; ++root) {
            auto *n = new TreeNode(root); 
            auto possible_left = build(a, root-1);
            auto possible_right = build(root+1, b);
            
            for (auto * l : possible_left) {
                n->left = l;
                for (auto *r : possible_right) {
                    n->right = r;
                    res.push_back(deep_copy(n));
                }
            }
        }
        return res;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);    
    }
};
