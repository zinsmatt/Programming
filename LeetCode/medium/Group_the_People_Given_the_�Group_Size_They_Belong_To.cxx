class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> m;
        vector<vector<int>> res;
        for (int i = 0; i < groupSizes.size(); ++i) {
            auto s = groupSizes[i];
            if (s == 1) {
                res.push_back({i});
            } else 
            {
                if (m.count(s) == 0) {
                    m[s] = {i};
                } else {
                    m[s].push_back(i);
                }
                if (m[s].size() == s) {
                    res.push_back(m[s]);
                    m.erase(s);
                }
            }
           
        }
        return res;
        
    }
};
