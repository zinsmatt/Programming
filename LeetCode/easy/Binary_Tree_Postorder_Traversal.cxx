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
    vector<int> post;
    
    void postorder(TreeNode* root)
    {
        if (root)
        {
            postorder(root->left);
            postorder(root->right);
            post.push_back(root->val);
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        post.clear();
        postorder(root);
        return post;
    }
};
