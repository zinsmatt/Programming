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
    int rangeSumBST(TreeNode* root, int L, int R) {
        return sum(root, L, R);        
    }
    
    int sum(TreeNode* n, int l, int r)
    {
        if (n)
        {
            int add = 0;
            if (n->val >= l && n->val <= r)
            {
                add = n->val;
            }
            auto temp = sum(n->left, l, r);
            auto temp2 = sum(n->right, l, r);
            return temp + temp2 + add;
        }
        return 0;
    }
};
