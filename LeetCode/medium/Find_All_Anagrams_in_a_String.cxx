class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> a(26, 0);
        vector<int> c(26, 0);

        for (auto x : p)
            a[x-'a']++;

        if (p.size() > s.size())
            return {};

        for (int i = 0; i < p.size(); ++i) {
            c[s[i]-'a']++;
        }
        vector<int> res;
        for (int i = 0; i < s.size()-p.size(); ++i) {
            if (a == c)
                res.push_back(i);
            c[s[i]-'a']--;
            c[s[i+p.size()]-'a']++;
        }
        if (a == c)
            res.push_back(s.size()-p.size());
        return res;
    }
};


