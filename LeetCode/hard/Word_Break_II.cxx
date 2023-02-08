class Solution {

    unordered_set<string> ss;
    vector<vector<int>> sep;

    void solve(const string& s, int i, vector<int> v, vector<vector<bool>>& exists) {
        int l = i;
        for (int n = 1; l+n <= s.size(); ++n) {
            if (exists[l][n]) {
                if (l+n >= s.size()) {
                    sep.push_back(v);
                } else {
                    auto vv = v;
                    vv.push_back(l+n);
                    solve(s, l+n, vv, exists);
                }
            }
            ++i;
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto &c : wordDict) {
            ss.insert(c);
        }

        vector<vector<bool>> exists(s.size(), vector<bool>(s.size()+1, false));
        for (int i = 0; i < s.size(); ++i) {
            for (int n = 1; i + n <= s.size(); ++n) {
                if (ss.count(s.substr(i, n))) {
                    exists[i][n] = true;
                }
            }
        }

        solve(s, 0, {}, exists);

        vector<string> res;
        for (auto &inds : sep) {
            stringstream o;
            int a = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (a < inds.size() && i == inds[a]) {
                    o << " ";
                    ++a;
                }
                o << s[i];
            }
            res.push_back(o.str());
        }

        return res;

    }
};
