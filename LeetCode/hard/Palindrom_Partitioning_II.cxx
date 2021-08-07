class Solution {
public:
    int minCut(string s) {
     
        vector<vector<pair<int, int>>> pals(s.size());
        for (int i = 0; i < s.size(); ++i)
        {
            int l = i, r=i;
            while (l >=0 && r < s.size() && s[l] == s[r])
            {
                pals[r].push_back(make_pair(l, r));
                --l;
                ++r;
            }
            
            l = i;
            r = i+1;
            while (l >=0 && r < s.size() && s[l] == s[r])
            {
                pals[r].push_back(make_pair(l, r));
                --l;
                ++r;
            }
        }
        // std::cout << "========================" << endl;
        
        // for (int i = 0; i < s.size(); ++i)
        // {
        //     std::cout << i << " \n";
        //     for (auto p : pals[i])
        //     {
        //         std::cout << "[" << p.first << " " << p.second << "] ";
        //     }
        //     cout << "\n";
        // }
        
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            int mini = std::numeric_limits<int>::max();
            for (const auto& p : pals[i])
            {
                int nouv = 1;
                if (p.first > 0)
                    nouv += dp[p.first-1];
                mini = std::min(mini, nouv);
            }
            dp[i] = mini;
        }
        return dp[s.size()-1]-1;
        
    }
};
