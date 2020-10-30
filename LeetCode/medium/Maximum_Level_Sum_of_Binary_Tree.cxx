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
    vector<long long int> t;
    vector<bool> used;
    
public:
    Solution() {
        t = std::vector<long long int>(10000, 0);
        used = std::vector<bool>(10000, false);
    }
    
    void f(TreeNode* n, int l)
    {
        if (n)
        {
            this->t[l] += n->val;
            this->used[l] = true;
            f(n->left, l+1);
            f(n->right, l+1);
        }
    }
    
    int maxLevelSum(TreeNode* root) {
        f(root, 0);
        auto best = t[0];
        auto best_i = 0;
        int i = 0;
        while (used[i])
        {
            if (t[i] > best)
            {
                best_i = i;
                best = t[i];
            }
            ++i;
        }
        return 1 + best_i;
        
    }
};
