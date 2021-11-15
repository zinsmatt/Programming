class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        for (int i = 0; i < triangle.size(); ++i)
        {
            dp.push_back(vector<int>(i+1, 0));
        }
        
        dp[0][0] = triangle[0][0];
        int l = 2;
        for (int i = 1; i < triangle.size(); ++i)
        {
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            dp[i][l-1] = dp[i-1][l-2] + triangle[i][l-1];
            for (int j = 1; j < l-1; ++j)
            {
                dp[i][j] = triangle[i][j] + std::min(dp[i-1][j-1], dp[i-1][j]);
            }
            ++l;
        }
        

        
        
        return *std::min_element(dp.back().begin(), dp.back().end());
        
    }
};
