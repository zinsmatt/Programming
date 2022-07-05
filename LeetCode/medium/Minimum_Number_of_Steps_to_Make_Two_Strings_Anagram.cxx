class Solution {
public:
    int minSteps(string s, string t) {
        std::unordered_map<char, int> ms, mt;
        for (auto c : s) {
            if (ms.count(c)) {
                ms[c]++;
            } else {
                ms[c] = 1;
            }
        }
        for (auto c : t) {
            if (mt.count(c)) {
                mt[c]++;
            } else {lee
                mt[c] = 1;
            }
        }
        
        int res = 0;
        for (auto it : ms) {
            if (mt.count(it.first))
                res += std::max(0, it.second-mt[it.first]);
            else 
                res += it.second;
        }
        return res;
    }
};


