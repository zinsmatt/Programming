class Solution {
    vector<int> to_code(const string& s)
    {
        vector<int> c(s.size(), -1);
        unordered_map<char, int> m;
        int a = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (m.find(s[i]) == m.end())
            {
                m[s[i]] = a++;
            }
            c[i] = m[s[i]];
        }
        return c;
    }
public:
    bool isIsomorphic(string s, string t) {
        return to_code(s) == to_code(t);
    }
};
