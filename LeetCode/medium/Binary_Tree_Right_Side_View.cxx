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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return vector<int>();
        vector<int> res;
        std::queue<TreeNode*> q;
        std::queue<int> l;
        q.push(root);
        l.push(0);
        while (q.empty() == false)
        {
            auto *n = q.front();
            q.pop();
            auto lvl = l.front();
            l.pop();
            if (lvl == res.size())
            {
                res.push_back(-1);
            }
            res[lvl] = n->val;

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
        return res;
    }
};