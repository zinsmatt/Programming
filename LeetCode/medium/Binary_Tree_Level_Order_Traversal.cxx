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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return vector<vector<int>>();
        std::queue<TreeNode*> q;
        std::queue<int> d;
        q.push(root);
        d.push(0);
        std::vector<std::vector<int>> res;
        while (!q.empty())
        {
            auto* a = q.front();
            q.pop();
            auto b = d.front();
            d.pop();

            if (b == res.size())
            {
                res.push_back(vector<int>());
            }
            res[b].push_back(a->val);
            if (a->left)
            {
                q.push(a->left);
                d.push(b+1);
            }
            if (a->right)
            {
                q.push(a->right);
                d.push(b+1);
            }
        }
        return res;
        
    }
};