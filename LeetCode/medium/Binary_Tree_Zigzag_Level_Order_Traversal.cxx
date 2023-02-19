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
    vector<vector<int>> levels;
    void solve(TreeNode *n, int l) {
        if (n) {
            levels[l].push_back(n->val);
            solve(n->left, l+1);
            solve(n->right, l+1);
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        levels.resize(2000);
        solve(root, 0);

        int n = 0;
        for (int i = 0; i < levels.size() && levels[i].size(); ++i) {
            if (i%2) {
                reverse(levels[i].begin(), levels[i].end());
            }
            ++n;
        }

        return vector<vector<int>>(levels.begin(), levels.begin()+n);
        
    }
};
