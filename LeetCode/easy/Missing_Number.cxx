class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int T = 100000;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i] < 0 ? nums[i] + T : nums[i];
            if (x < nums.size()) {
                nums[x] -= T;
            }
        }
      

        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0)
                res = i;
        }
        return res;
    }
};
