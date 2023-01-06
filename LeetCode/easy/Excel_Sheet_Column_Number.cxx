class Solution {
public:
    int titleToNumber(string columnTitle) {
        int x = 0;
        for (auto s : columnTitle) {
            x *= 26;
            x += s-'A'+1;
        }
        return x;
    }
};
