class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> dp(amount+1, std::numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 0; i < dp.size(); ++i)
        {
            for (auto k : coins) {
                if (i-k >= 0) {
                    dp[i] = std::min(dp[i], dp[i-k]+1);
                }
            }
        }
        if (dp[amount] == std::numeric_limits<int>::max())
            return -1;
        return dp[amount];
    }
};


