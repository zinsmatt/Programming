class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<pair<string, int>>> pals(s.size(), vector<pair<string, int>>());
        
        for (int i = 0; i < s.size(); ++i)
        {
            for (int n = 0; i+n < s.size() && i-n >= 0; ++n)
            {
                if (s[i+n] != s[i-n])
                    break;
                pals[i+n].push_back({s.substr(i-n, n*2+1), i-n});
            }
            
            for (int n = 0; i+n < s.size() && i-1-n >= 0; ++n)
            {
                if (s[i+n] != s[i-1-n])
                    break;
                pals[i+n].push_back({s.substr(i-1-n, (n+1)*2), i-1-n});
            }
        }
        
        vector<vector<string>> res;        
        queue<pair<int, vector<string>>> q;
        q.push({s.size(), {}});
        while (!q.empty())
        {
            auto [end, vs] = q.front();
            q.pop();
            if (end == 0)
            {
                reverse(vs.begin(), vs.end());
                res.push_back(std::move(vs));
                continue;
            }
            else if (end < 0)
            {
                continue;
            }
            for (auto& p: pals[end-1])
            {
                auto cpy = vs;
                cpy.push_back(p.first);
                q.push({p.second, cpy});
            }
        }
        return res;
    }
};
