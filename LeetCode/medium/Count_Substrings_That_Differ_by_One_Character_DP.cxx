class Solution {
public:
    int countSubstrings(string s, string t) {
   
        // DP of strings identical ending in s[i] and t[j]
        vector<vector<int>> dp(s.size(), std::vector<int>(t.size(), 0));
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < t.size(); ++j) {


                if (s[i] == t[j]) {
                    if (i > 0 && j > 0)
                        dp[i][j] = dp[i-1][j-1];
                    dp[i][j]++;
                }
            }
        }


        // for (auto v : dp)
        // {
        //     for (auto x : v) {
        //         std::cout << x << " " ;
        //     }
        //     std::cout << "\n";
        // }
        
        // 2nd DP of strings with one different character ending in s[i] and t[j]
        //if same chars: dp[i][j] = dp[i-1][j-1]
        //if different chars: dp[i][j] = 1 + nb of identical strings ending in s[i] and t[j] (computed by the first dp)
        vector<vector<int>> dpdiff(s.size(), std::vector<int>(t.size(), 0));
          for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < t.size(); ++j) {

                if (s[i] == t[j]) {
                    if (i > 0 && j > 0)
                        dpdiff[i][j] = dpdiff[i-1][j-1];
                } else {
                    if (i> 0 && j > 0)
                        dpdiff[i][j] = dp[i-1][j-1];
                    dpdiff[i][j]++;
                }
            }
        }
        int res = 0;
        for (auto& v : dpdiff) {
            res += std::accumulate(v.begin(), v.end(), 0);
        }
        return res;
    }
};
