class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<long> dp(n, 0);

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&ages, &scores](int i, int j) {
            if (ages[i] == ages[j])
                return scores[i] < scores[j];
            return ages[i] < ages[j];
        });

        for (int i = 0; i < n; ++i)
            dp[i] = scores[indices[i]];


        long res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (scores[indices[j]] <= scores[indices[i]]) {
                    dp[i] = max(dp[i], dp[j] + scores[indices[i]]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;

    }
};
