class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> DP(text1.size(), vector<int>(text2.size(), 0));
        
        DP[0][0] = text1[0] == text2[0];
        for (int i = 1; i < text1.size(); ++i)
            DP[i][0] = max(DP[i-1][0], (int)(text1[i] == text2[0]));
        for (int j = 1; j < text2.size(); ++j)
            DP[0][j] = max(DP[0][j-1], (int)(text1[0] == text2[j]));
        
        int res = 0;
        for (int i = 1; i < text1.size(); ++i)
        {
            for (int j = 1; j < text2.size(); ++j)
            {
                if (text1[i] == text2[j])
                {
                    DP[i][j] = DP[i-1][j-1] + 1;
                }
                else
                {
                    DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
                }
                res = max(res, DP[i][j]);
            }
        }
        return res;
    }
};
