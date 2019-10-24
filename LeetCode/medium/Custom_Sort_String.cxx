class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> map(26, -1);
        for (int i = 0; i < S.size(); ++i)
        {
            map[S[i] - 'a'] = i;
        }
        
        vector<int> count(26, 0);
        stringstream other;
        for (auto& c : T)
        {
            if (map[c - 'a'] >= 0)
            {
                ++count[map[c - 'a']];
            }
            else
            {
                other << c;
            }
        }
        stringstream res;
        for (int i = 0; i < S.size(); ++i)
        {
            for (int j = 0; j <  count[i]; ++j)
            {
                res << S[i];
            }
        }
        res << other.str();
        return res.str();
    }
};