class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> m;
        for (int i = 0; i < order.size(); ++i) {
            m[order[i]] = 'a' + i;
        }

        for (auto &w : words) {
            for (auto& c : w) {
                c = m[c];
            }
        }

        for (int i = 1; i < words.size(); ++i)
            if (words[i-1] > words[i])
                return false;
        return true;
    }
};
