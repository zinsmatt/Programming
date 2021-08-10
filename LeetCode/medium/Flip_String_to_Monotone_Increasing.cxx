class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<vector<int>> dp(2, vector<int>(s.size(), 0));

        if (s[0] == '0')
            dp[1][0] = 1;
        else
            dp[0][0] = 1;

        for (int i = 1; i < s.size(); ++i)
        {
            dp[0][i] = dp[0][i-1] + static_cast<int>(s[i] == '1');
            dp[1][i] = std::min(dp[0][i-1], dp[1][i-1]) + static_cast<int>(s[i] == '0');
        }
        return std::min(dp[0].back(), dp[1].back());        
    }
};
