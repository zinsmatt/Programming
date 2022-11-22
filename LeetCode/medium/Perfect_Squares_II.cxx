class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, std::numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; i + j*j <= n; ++j) {
                dp[i + j*j] = std::min(dp[i + j*j], dp[i] + 1);
            }
        }
        return dp[n];
    }
};
