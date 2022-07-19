class Solution {
public:
    int myAtoi(string s) {
        if (s.size() == 0) return 0;
        int i = 0; 
        while (i < s.size() && s[i] == ' ')
            ++i;
        if (i >= s.size()) return 0;
        int sign = 1;
        if (s[i] == '+') ++i;
        else if (s[i] == '-') {
            sign = -1;
            ++i;
        }
        while (i < s.size() && s[i] == '0')
            ++i;
        int n = 0;
        long long res = 0;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9' && n <= 12) {
            res *= 10;
            res += s[i] - '0';
            ++i;
            ++n;
        }
        
        res *= sign;
        if (res < std::numeric_limits<int>::min())
            res = std::numeric_limits<int>::min();
        if (res > std::numeric_limits<int>::max())
            res = std::numeric_limits<int>::max();
        return static_cast<int>(res);
    }
};

