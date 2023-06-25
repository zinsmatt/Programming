class Solution {
    long long M = 1e9+7;

    long long solve(vector<vector<long long>>& dp, vector<int>& locations, int cur, int finish, int fuel) {
        if (fuel < 0)
            return 0;
        if (dp[cur][fuel] != -1)
            return dp[cur][fuel];
        long long res = 0;
        if (cur == finish)
            ++res;
        
        for (int i = 0; i < locations.size(); ++i) {
            if (i != cur) {
                res = (res + solve(dp, locations, i, finish, fuel-abs(locations[i]-locations[cur])) % M) % M;
            }
        }
        res %= M;
        dp[cur][fuel] = res;
        return res;


    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<long long>> dp(n, vector<long long>(fuel+1, -1));
        
        return solve(dp, locations, start, finish, fuel);
      
        
    }
};
