class Solution {
    int res = 0;
    int split(vector<int>& nums, int l, int r) {
        if (l < r) {
            int m = (l+r) / 2;
            int left = split(nums, l, m);
            int right = split(nums, m+1, r);
            return left ^ right;
            
        } else { // l == r
            return nums[l];
        }
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        return split(nums, 0, nums.size()-1);
    }
};
