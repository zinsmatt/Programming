class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<vector<int>> DP(2, vector<int>(s.size(), 0));
        DP[0][0] = s[0]-'0';
        DP[1][0] = 1 - (s[0]-'0');

        for (int i = 1; i < s.size(); ++i) {
            int x = s[i]-'0';
            DP[0][i] = DP[0][i-1] + x;
            DP[1][i] = min(DP[0][i-1], DP[1][i-1]) + (1-x);
        }
        return min(DP[0][s.size()-1], DP[1][s.size()-1]);
    }
};
