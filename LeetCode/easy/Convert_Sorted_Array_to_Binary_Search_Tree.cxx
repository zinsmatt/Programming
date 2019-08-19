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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return f(0, nums.size() - 1, nums);
    }
    
    TreeNode* f(int a, int b, vector<int> const& nums)
    {
        if (a <= b)
        {
            int m = (a + b) / 2;
            TreeNode* nouv = new TreeNode(nums[m]);
            nouv->left = f(a, m-1, nums);
            nouv->right = f(m+1, b, nums);
            return nouv;
        }
        return nullptr;
    }
};