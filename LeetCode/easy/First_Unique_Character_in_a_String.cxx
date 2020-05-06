class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (auto c : s)
        {
            if (m.find(c) == m.end())
                m[c] = 1;
            else
                m[c]++;
        }
        int i = 0;
        for (auto c : s)
        {
            if (m[c] == 1)
                return i;
            ++i;
        }
        return -1;
    }
};
