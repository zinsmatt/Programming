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
    std::pair<int, int> find_nodes(TreeNode* n, int x, int y, int d)
    {
        if (n)
        {
            if (n->left && (n->val == x && n->left->val == y || n->val == y && n->left->val == x))
                return {0, 1};
            if (n->right && (n->val == x && n->right->val == y || n->val == y && n->right->val == x))
                return {0, 1};
            if (n->left && n->right && (n->left->val == x && n->right->val == y || n->left->val == y && n->right->val == x))
                return {0, 1};
            auto resl = find_nodes(n->left, x, y, d+1);
            auto resr = find_nodes(n->right, x, y, d+1);
            
            
            std::pair<int, int> cur = {-1, -1};
            if (resl.first != -1) cur.first = resl.first;
            if (resr.first != -1) cur.first = resr.first;
            
            if (resl.second != -1) cur.second = resl.second;
            if (resr.second != -1) cur.second = resr.second;
            
            if (n->val == x)
                cur.first = d;
            if (n->val == y)
                cur.second = d;
            
            return cur;                
        }
        return {-1, -1};
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (x == y) return false;
        
        auto cousins = find_nodes(root, x, y, 0);
        return cousins.first == cousins.second;
        
    }
};
