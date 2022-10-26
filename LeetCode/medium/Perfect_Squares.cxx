class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(10001, 100000);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= 100; ++j) {
                if (i+j*j <= n)
                    dp[i+j*j] = std::min(dp[i+j*j], dp[i] + 1);
            }
        }
        return dp[n];
        
    }
};
