class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int res = 0;
        int cur_min = nums[0];
        for (auto x : nums) {
            if (x > cur_min + k) {
                ++res;
                cur_min = x;            
            }
        }
        return res+1;
    }
};
