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
    vector<double> averageOfLevels(TreeNode* root) {
        std::queue<TreeNode*> q;
        queue<int> lvl;
        vector<double> res;
        q.push(root);
        lvl.push(0);
        int cur_lvl = 0;
        int nb = 0;
        double s = 0;
        while (!q.empty())
        {
            auto *p = q.front();
            q.pop();
            auto l = lvl.front();
            lvl.pop();
            if (l == cur_lvl)
            {
                s += p->val;
                nb++;
            }
            else
            {
                res.push_back(s / nb);
                cur_lvl = l;
                s = p->val;
                nb = 1;
            }
            if (p->left)
            {
                q.push(p->left);
                lvl.push(l+1);   
            }
            if (p->right)
            {
                q.push(p->right);
                lvl.push(l+1);   
            }
        }
        if (nb > 0)
        {
            res.push_back(s / nb);
        }
        return res;
    }
};