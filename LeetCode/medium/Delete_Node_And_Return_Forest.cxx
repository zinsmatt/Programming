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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        solve2(root, to_delete, res);
        if (std::find(to_delete.begin(), to_delete.end(), root->val) == to_delete.end())
        {
            res.push_back(root);
        }
        return res;
    }
    
    TreeNode* solve2(TreeNode* n, const vector<int>& to_delete, vector<TreeNode*>& roots)
    {
        if (n)
        {
            auto *l = solve2(n->left, to_delete, roots);
            auto *r = solve2(n->right, to_delete, roots);
            if (std::find(to_delete.begin(), to_delete.end(), n->val) != to_delete.end())
            {
                if (l)
                    roots.push_back(l);
                if (r) 
                    roots.push_back(r);
                return nullptr;
            }
            n->left = l;
            n->right = r;
            return n;
        }
        return nullptr;
    }
};