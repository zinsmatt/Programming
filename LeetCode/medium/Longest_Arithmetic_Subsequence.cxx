class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1010, 1));
        int res = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                auto d = nums[i] - nums[j];
                auto idx = d + 500;
                dp[i][idx] = dp[j][idx] + 1;
                res = max(res, dp[i][idx]);
            }
        }
        return res;
    }
};
