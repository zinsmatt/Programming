class Solution {
    

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_map<string, int> m;
        for (const auto& w: wordDict)
        {
            m[w] = 1;
        }
        
        vector<bool> good(s.size()+1, false);
        good[0] = true;
        for (int i = 0; i < s.size(); ++i)
        {
            if (!good[i])
                continue;
            for (int j = i; j < s.size(); ++j)
            {
                if (m.find(s.substr(i, j-i+1)) != m.end())
                {
                    good[j+1] = true;
                }
            }
        }
       
        return good.back();
        
    }
};
