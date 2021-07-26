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
    
    
    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        // for (auto& x : nums) cout << x << " ";
        // cout << "\n";
        if (nums.size() == 0) return nullptr;
        if (nums.size() == 1) return new TreeNode(nums[0]);
        int m = nums.size()/2;
        
        auto* elem = new TreeNode(nums[m]);
        elem->left = sortedArrayToBST(std::vector<int>(nums.begin(), nums.begin()+m));
        elem->right = sortedArrayToBST(std::vector<int>(nums.begin()+m+1, nums.end()));
        return elem;
    }
};
