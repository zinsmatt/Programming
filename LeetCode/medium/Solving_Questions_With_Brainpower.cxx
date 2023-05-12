class Solution {


    long long solve(int i, vector<vector<int>>& questions, vector<long long>& dp) {
        if (i >= questions.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        
        auto res = max((long long)questions[i][0] + solve(i+questions[i][1]+1, questions, dp), solve(i+1, questions, dp));
        dp[i] = res;
        return res;
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+10, -1);
        return solve(0, questions, dp);


        

    
    }
};
