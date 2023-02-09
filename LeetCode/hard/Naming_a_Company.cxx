class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> prefixes(26);
        for (auto &w : ideas) {
            prefixes[w[0]-'a'].insert(w.substr(1));
        }

        long long res = 0;
        for (int i = 0; i < prefixes.size(); ++i) {
            for (int j = i + 0; j < prefixes.size(); ++j) {
                long long nb_common = 0;
                for (auto &x : prefixes[i]) {
                    if (prefixes[j].count(x))
                        ++nb_common;
                }

                res += 2 * (prefixes[i].size() - nb_common) * (prefixes[j].size() - nb_common);
            }
        }
        return res;

    }
};
