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
	tuple<bool, bool, TreeNode*> solve(TreeNode* n, TreeNode* p, TreeNode* q) {
		if (!n) return {false, false, nullptr};
		bool pp = false;
		bool qq = false;
		if (n == p)
			pp = true;
		if (n == q)
			qq = true;
		auto [pp1, qq1, a1] = solve(n->left, p, q);
		auto [pp2, qq2, a2] = solve(n->right, p, q);
		if (!a1)
			a1 = a2;
		pp |= pp1 | pp2;
		qq |= qq1 | qq2;
		if (!a1 && pp && qq)
		{
			a1 = n;
		}
		return {pp, qq, a1};
}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto [pp, qq, a] = solve(root, p, q);
        return a;
    }
};



