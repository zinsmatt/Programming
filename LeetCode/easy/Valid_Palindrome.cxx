class Solution {
public:
    bool isAlphaNumeric(char x) {
        return x >='0' && x <= '9' || x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z';
    }
    
    bool isPalindrome(string s) {
        int a = 0;
        int b = s.size() - 1;
        bool res = true;
        while (a < b)
        {
            while (a < s.size() && !isAlphaNumeric(s[a]))
                ++a;
            while (b >= 0 && !isAlphaNumeric(s[b]))
                --b;
            if (a >= s.size() || b < 0)
                break;
            if (std::tolower(s[a]) != std::tolower(s[b])) {
                res = false;
                break;
            }
            ++a;
            --b;
                
        }
        return res;
    }
};