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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> s1;
        sequ(root1, s1);
        vector<int> s2;
        sequ(root2, s2);
        return s1 == s2;
    }
    
    void sequ(TreeNode* n, vector<int>& res)
    {
        if (n)
        {
            if (n->left || n->right)
            {
                sequ(n->left, res);
                sequ(n->right, res);
            }
            else
            {
                res.push_back(n->val);             
            }
        }
    }
};