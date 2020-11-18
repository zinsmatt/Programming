class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        std::vector<std::string> res;
        for (auto& w : words) {
            std::vector<char> map_to(26, -1);
            std::vector<char> used(26, -1);
            bool ok = true;
            for (int i = 0; i < w.size(); ++i) {
                if (map_to[pattern[i]-'a'] == -1) {
                    if (used[w[i]-'a'] == -1 || used[w[i]-'a'] == pattern[i]) {
                        map_to[pattern[i]-'a'] = w[i];
                        used[w[i]-'a'] = pattern[i];
                    } else {
                        ok = false;
                        break;
                    }
                } else {
                    if (map_to[pattern[i]-'a'] != w[i]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok)
                res.push_back(w);
        }
        return res;
    }
};
