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
    int find(TreeNode* n, int target)
    {
        if (!n) return false;
        if (n->val == target) return true;
        if (n->val > target)
            return find(n->left, target);
        else
            return find(n->right, target);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* pt = q.front();
            q.pop();
            if (!pt) continue;
            if (pt->val * 2 != k && find(root, k - pt->val))
                return true;
            q.push(pt->left);
            q.push(pt->right);            
        }
        return false;
        
    }
};
