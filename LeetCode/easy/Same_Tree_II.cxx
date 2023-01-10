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
    bool check(TreeNode *a, TreeNode *b) {
        if (!a && !b) 
            return true;
        if (!a || !b)
            return false;
        
        if (a->val != b->val)
            return false;
        
        return check(a->left, b->left) && check(a->right, b->right);
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);        
    }
};
