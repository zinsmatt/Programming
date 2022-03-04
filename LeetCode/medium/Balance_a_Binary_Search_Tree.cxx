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
    void inorder(TreeNode* n, vector<int>& v) {
        if (n)
        {
            inorder(n->left, v);
            v.push_back(n->val);
            inorder(n->right, v);
        }
    }

    TreeNode* recursive_build(const vector<int>& v, int l, int r) {
        if (l > r) return nullptr;
        
        int m = (l+r) / 2;
        auto* n = new TreeNode(v[m]);
        n->left = recursive_build(v, l, m-1);
        n->right = recursive_build(v, m+1, r);
        return n;
    }
    
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return recursive_build(v, 0, v.size()-1);
    }
};
