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
    int countNodes(TreeNode* root) {
        auto [h, r] = solve(root, 0, 0);
        return pow(2, h) - 1 + r +1;
    }
    
    pair<int, int> solve(TreeNode* n, int h, int r)
    {
        if (n)
        {
            auto [h_l, r_l] = solve(n->left, h+1, 2*r);
            auto [h_r, r_r] = solve(n->right, h+1, 2*r+1);
            if (h_l == 0 && h_r == 0)
            {
                return make_pair(h, r);
            }
            if (h_l == 0)
            {
                return make_pair(h_r, r_r);
            }
            if (h_r == 0)
            {
                return make_pair(h_l, r_l);
            }
            
            if (h_r > h_l)
                return make_pair(h_r, r_r);
            else if (h_r < h_l)
                return make_pair(h_l, r_l);
            else
            {
                if (r_r > r_l)
                    return make_pair(h_r, r_r);
                else
                    return make_pair(h_l, r_l);
            }
        }
        return make_pair(0, -1);
    }
};