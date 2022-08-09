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
	vector<int> view;
	void solve(TreeNode *n, int lvl) {
		if (!n) return;

		view[lvl] = n->val;
		solve(n->left, lvl+1);
        solve(n->right, lvl+1);
	}
    
public:
    vector<int> rightSideView(TreeNode* root) {
        view.resize(101, 404);
        solve(root, 0);
        return vector<int>(view.begin(), find(view.begin(), view.end(), 404));
    }
};

