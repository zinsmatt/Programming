class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> code(strs.size(), vector<int>(26, 0));
        for (int i = 0; i < strs.size(); ++i)
        {
            for (auto c : strs[i])
            {
                ++code[i][c - 'a'];
            }
        }
        
        map<vector<int>, int> tas;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); ++i)
        {
            if (tas.find(code[i]) != tas.end())
            {
                res[tas[code[i]]].push_back(strs[i]);
            }
            else
            {
                tas[code[i]] = res.size();
                res.push_back({strs[i]});
            }
        }
        return res;
        
    }
};