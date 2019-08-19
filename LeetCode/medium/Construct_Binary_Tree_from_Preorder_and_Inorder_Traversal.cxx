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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return f(preorder, inorder, 0, 0, inorder.size()-1);
    }

    TreeNode* f(vector<int>& preorder, vector<int>& inorder, int idx, int a, int b)
    {
        if (a == b)
        {
            return new TreeNode(inorder[a]);
        }
        else if (a < b)
        {
            auto * nouv = new TreeNode(preorder[idx]);
            int i = a;
            for (i = a; i <= b && preorder[idx] != inorder[i]; ++i)
            { }
            nouv->left = f(preorder, inorder, idx+1, a, i-1);
            nouv->right = f(preorder, inorder, idx+(i-a+1), i+1, b);
            return nouv;
        }
        else
        {
            return nullptr;
        }
    }
};