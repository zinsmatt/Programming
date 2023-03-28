class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int M = std::numeric_limits<int>::max();
        vector<int> dp(days.size(), M);

        dp[0] = std::min(costs[0], std::min(costs[1], costs[2]));
        for (int i = 1; i < days.size(); ++i) {
            int a1 = dp[i-1] + costs[0];
            int a7 = costs[1];
            int a30 = costs[2];

            int j = i-1;
            int min_cost = M;
            while (j >= 0 && days[i]-days[j] < 7) {
                min_cost = min(min_cost, dp[j]);
                --j;
            }
        
            if (j >= 0) {
                min_cost = min(min_cost, dp[j]);
                if (min_cost == M)
                    a7 = M;
                else
                    a7 += min_cost;
            }
            
            j = i-1;
            min_cost = M;
            while (j >= 0 && days[i]-days[j] < 30) {
                min_cost = min(min_cost, dp[j]);
                --j;
            }
        
            if (j >= 0){
                min_cost = min(min_cost, dp[j]);
                if (min_cost == M)
                    a30 = M;
                else
                    a30 += min_cost;
            }
            
            dp[i] = min(a1, min(a7, a30));
        }
        return dp.back();
    }
};
