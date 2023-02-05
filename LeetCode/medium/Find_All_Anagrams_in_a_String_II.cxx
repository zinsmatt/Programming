class Solution {
    void print(vector<int>& v)
    {
        for (auto x : v)
        cout << x << " ";
        cout << "\n";
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ref(26, 0);
        for (auto c : p)
            ++ref[c-'a'];
        vector<int> res;
        vector<int> cur(26, 0);
        for (int i = 0; i < p.size() && i < s.size(); ++i) {
            ++cur[s[i]-'a'];
        }
        if (cur == ref)
            res.push_back(0);

        int i = 0;
        while (i + p.size()  < s.size()) {
            --cur[s[i] - 'a'];
            ++cur[s[i+p.size()] - 'a'];
            ++i;
            if (cur == ref)
                res.push_back(i);
        }
        return res;
    }
};
