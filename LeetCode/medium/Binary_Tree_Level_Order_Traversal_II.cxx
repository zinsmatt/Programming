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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        std::queue<pair<TreeNode*, int>> q;
        if (root)
            q.push({root, 0});
        while (!q.empty()) {
            auto [p, l] = q.front();
            q.pop();
            if (res.size() > l)
                res[l].push_back(p->val);
            else
                res.push_back({p->val});

            if (p->left)
                q.push({p->left, l+1});
            if (p->right)
                q.push({p->right, l+1});

        }
        return res;        
    }
};



