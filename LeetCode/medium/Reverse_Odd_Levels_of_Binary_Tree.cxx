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
    vector<list<int>> values;

    void fill(TreeNode* n, int l) {
        if (n) {
            if (l % 2 == 1)
                values[l].push_back(n->val);
            fill(n->left, l+1);
            fill(n->right, l+1);
        }
    }

    void reassign(TreeNode *n, int l) {
        if (n) {
            if (l % 2 == 1) {
                n->val = values[l].back();
                values[l].pop_back();
            }
            reassign(n->left, l+1);
            reassign(n->right, l+1);
        }
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        values.resize(20);
        fill(root, 0);

        reassign(root, 0);
        return root;        
    }
};
