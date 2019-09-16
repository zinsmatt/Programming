class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counts0(26, 0);
        vector<int> counts1(26, 0);
        for (auto c : s)
            counts0[c-'a']++;
        for (auto c : t)
            counts1[c-'a']++;
        for (int i = 0; i < 26; ++i)
        {
            if (counts0[i] != counts1[i])
                return false;
        }
        return true;
    }
};