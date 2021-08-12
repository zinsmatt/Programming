class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto s : strs)
        {
            auto ks = s;
            sort(ks.begin(), ks.end());
            if (m.find(ks) == m.end())
            {
                m[ks] = {s};
            }
            else
            {
                m[ks].push_back(s);                
            }
        }
        vector<vector<string>> res;
        for (auto it: m)
        {
            res.push_back(it.second);
        }
        return res;
    }
};
