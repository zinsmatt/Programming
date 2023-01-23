class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<int>> pals(s.size());
        for (int i = 0; i < s.size(); ++i) {
            int k = 0;
            while (i-k >= 0 && i+k < s.size() && s[i-k] == s[i+k]) {
                pals[i-k].push_back(k*2+1);
                ++k;
            }
        }

        for (int i = 0; i < s.size(); ++i) {
            int k = 0;
            while (i-k >= 0 && i+1+k < s.size() && s[i-k] == s[i+1+k]) {
                pals[i-k].push_back(k*2+2);
                ++k;
            }
        }

        vector<vector<string>> res;
        queue<pair<int, vector<string>>> q;
        q.push({0, {}});
        while (!q.empty()) {
            auto [i, v] = q.front();
            q.pop();

            for (auto n : pals[i]) {
                auto v_cpy = v;
                v_cpy.push_back(s.substr(i, n));
                if (i + n == s.size()) {
                    res.push_back(v_cpy);
                } else {
                    q.push({i+n, v_cpy});
                }
            }
        }
        return res;
    }
};
