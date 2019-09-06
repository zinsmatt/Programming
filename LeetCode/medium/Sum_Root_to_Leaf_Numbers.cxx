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
    int sumNumbers(TreeNode* root) {
        process(root, 0);
        return sum;
    }
    void process(TreeNode * n, int total)
    {
        if (n)
        {
            total *= 10;
            total += n->val;
            if (n->left == nullptr && n->right == nullptr)
            {
                sum += total;
            }
            else
            {
                process(n->left, total);
                process(n->right, total);
            }
        }
    }
    int sum = 0;
    
};