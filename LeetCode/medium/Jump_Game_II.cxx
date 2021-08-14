class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), std::numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 0; i < nums.size()-1; ++i)
        {
            for (int d = 1; d <= nums[i] && i+d < nums.size(); ++d)
            {
                dp[i+d] = std::min(dp[i+d], dp[i] + 1);
            }
        }
        return dp.back();
    }
};
