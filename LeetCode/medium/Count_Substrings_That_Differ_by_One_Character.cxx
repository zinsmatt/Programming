class Solution {
public:
    int countSubstrings(string s, string t) {
        std::unordered_map<string, int> mt;
        for (int i = 0; i < t.size(); ++i) {
            for (int j = i; j < t.size(); ++j) {
                mt[t.substr(i, j-i+1)]++;
            }
        }
        long long res = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                auto x = s.substr(i, j-i+1);
                for (int k = 0; k < x.size(); ++k) {
                    auto w = x;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == x[k]) continue;
                        w[k] = c;
                        if (mt.count(w))
                            res += mt[w];
                    }
                }
                
            }
        }
        return res;
    }
};
