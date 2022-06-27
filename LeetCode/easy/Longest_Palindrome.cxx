class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(52, 0);
        for (auto c : s) {
            if (c >= 'a') {
                count[c-'a'+26]++;
            } else {
                count[c-'A']++;
            }
        }
        int bonus = 0;
        int res = 0;
        for (auto x : count) {
            res += (x / 2) * 2;
            if (x % 2) 
                bonus = 1;
        }
        return res + bonus;
    }
};
