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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        check(root, vector<int>(), 0, sum);
        return res;
    }
    
    void check(TreeNode *h, vector<int> cur, int c, int s)
    {
        if (h)
        {
            c += h->val;
            cur.push_back(h->val);
            if (!h->left && !h->right)
            {
                if (c == s)
                {
                    res.push_back(cur);
                }
            }
            else
            {
                check(h->right, cur, c, s);
                check(h->left, cur, c, s);
            }
            
        }
    }
    
    vector<vector<int>> res;
};