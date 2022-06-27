class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> m1, m2;
        for (auto c : s) {
            if (m1.find(c) != m1.end()) {
                ++m1[c];
            } else {
                m1[c] = 1;
            }
        }
        for (auto c : t) {
                if (m2.find(c) != m2.end()) {
                    ++m2[c];
                } else {
                    m2[c] = 1;
            }
        }
        return m1 == m2;
    }
};
