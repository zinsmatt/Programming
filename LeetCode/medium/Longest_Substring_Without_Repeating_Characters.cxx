class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> m;
        int res = 0;
        int left = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (m.find(s[i]) != m.end())
            {
                left = std::max(left, m[s[i]]+1);
            }
            m[s[i]] = i;
            res = std::max(res, i-left+1);
        }
        return res;
    }
};
