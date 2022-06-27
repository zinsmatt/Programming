class Solution {
    bool is_alphanum(char c) {
        return c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
    char to_lower(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c-'A' + 'a';
        } else {
            return c;
        }
    }
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        while (l < r) {
            while (l < r && !is_alphanum(s[l])) ++l;
            while (r > l && !is_alphanum(s[r])) --r;
            s[l] = to_lower(s[l]);
            s[r] = to_lower(s[r]);
            if (s[l] != s[r])
                return false;
            ++l;
            --r;
        }
        return true;
        
    }
};
