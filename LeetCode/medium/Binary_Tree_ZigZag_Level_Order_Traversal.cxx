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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::queue<int> l;
        std::vector<std::vector<int>> res;
        if (!root)
            return res;
        q.push(root);
        l.push(0);
        while (q.empty() == false)
        {
            auto* n = q.front();
            q.pop();
            auto lvl = l.front();
            l.pop();
            
            if (lvl == res.size())
            {
                res.push_back(std::vector(1, n->val));
            }
            else
            {
                res[lvl].push_back(n->val);
            }
            
            if (n->left)
            {
                q.push(n->left);
                l.push(lvl+1);
            }
            
            if (n->right)
            {
                q.push(n->right);
                l.push(lvl+1);
            }
        }
        for (int i = 1; i < res.size(); i+=2)
        {
            std::reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};