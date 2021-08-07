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
    
    vector<TreeNode*> pre;
    
    void pre_order(TreeNode* n)
    {
        if (n)
        {
            pre_order(n->left);
            pre.push_back(n);
            pre_order(n->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        pre_order(root);
        for (int i = 0; i < pre.size(); ++i)
        {
            for (int j = i+1; j < pre.size(); ++j)
            {
                if (pre[i]->val > pre[j]->val)
                {
                    std::swap(pre[i]->val, pre[j]->val);
                }
            }
        }
    }
};
