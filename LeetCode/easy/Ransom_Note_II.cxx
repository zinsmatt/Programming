class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m, r;
        for (auto c : magazine) {
            if (m.find(c) != m.end())
                ++m[c];
            else
                m[c] = 1;
        }
        for (auto c : ransomNote) {
            if (m.find(c) != r.end() && m.at(c) > 0)
                --m[c];
            else
                return false;
        }
        return true;
    }
};
