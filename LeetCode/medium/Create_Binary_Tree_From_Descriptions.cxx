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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_map<int, bool> is_root;

        for (auto& desc : descriptions) {
            if (nodes.count(desc[0]) == 0)
                nodes[desc[0]] = new TreeNode(desc[0]);
            if (nodes.count(desc[1]) == 0)
                nodes[desc[1]] = new TreeNode(desc[1]);
            is_root[desc[0]] = true;
            is_root[desc[1]] = true;
        }
        for (auto& desc : descriptions) {
            if (desc[2])
                nodes[desc[0]]->left = nodes[desc[1]];
            else
                nodes[desc[0]]->right = nodes[desc[1]];
            is_root[desc[1]] = false;
        }
        for (auto b : nodes) {
            if (is_root[b.first])
                return b.second;
        }
        return nullptr;
    }
};
