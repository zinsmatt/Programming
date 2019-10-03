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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
    
    TreeNode* build(vector<int>& nums, int l, int r)
    {
        if (l <= r)
        {
            int max_idx = distance(nums.begin(), max_element(nums.begin() + l, nums.begin() + r + 1));
            auto* nouv = new TreeNode(nums[max_idx]);
            nouv->left = build(nums, l, max_idx-1);
            nouv->right = build(nums, max_idx+1, r);
            return nouv;
        }
        return nullptr;
    }
};
