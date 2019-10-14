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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return check(root1, root2);
    }
    
    bool check(TreeNode* n1, TreeNode* n2)
    {
        if (n1 && n2)
        {
            if (n1->val == n2->val)
            {
                return check(n1->left, n2->left) && check(n1->right, n2->right) ||
                       check(n1->right, n2->left) && check(n1->left, n2->right);
                    
            }
            else
            {
                return false;
            }
        }
        else if (!n1 && !n2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};