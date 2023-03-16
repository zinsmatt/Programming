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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l, int r, int ll, int rr) {
        int m = inorder.size();
        if (l> r || ll > rr || l < 0 || r < 0 || ll < 0 || rr < 0 || l >= m || r >= m || ll >= m || rr >= m) {
            return nullptr;
        } else if (l == r) {
            return new TreeNode(inorder[l]);
        } else {
            int v = postorder[rr];
            TreeNode* n = new TreeNode(v);
            int idx = std::distance(inorder.begin()+l, std::find(inorder.begin(), inorder.end(), v));
            n->left = build(inorder, postorder, l, l+idx-1, ll, ll+idx-1);
            n->right = build(inorder, postorder, l+idx+1, r, ll+idx, rr-1);
            return n;
        }
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);   
    }
};
