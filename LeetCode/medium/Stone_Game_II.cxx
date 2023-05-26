class Solution {
    int dp[101][101];
    vector<int> suffsum;

    int solve(vector<int>& piles, int i, int m) {
        if (i >= piles.size()) return 0;
        if (i+2*m >= piles.size())
            return suffsum[i];
        
        if (dp[i][m] != 0)
            return dp[i][m];
        
        int res = 0;
        for (int x = 1; x <= 2*m; ++x) {
            res = max(res, suffsum[i] - solve(piles, i+x, max(x, m)));
        }
        dp[i][m] = res;
        return res;
    }

public:
    int stoneGameII(vector<int>& piles) {
        suffsum.resize(piles.size());
        suffsum.back() = piles.back();

        for (int i = piles.size()-2; i >= 0; --i) {
            suffsum[i] = suffsum[i+1] + piles[i];
        }
        
        memset(dp, 0, 101*101);
        return solve(piles, 0, 1);
    }
};
