class Solution {
public:
    string longestPalindrome(string s) {
	string res = "";
    for (int i = 0; i < s.size(); ++i) {
        int j = 0;
        while (i-j >= 0 && i+j < s.size() && s[i-j] == s[i+j])
            ++j;
        --j;

        if (j*2+1 > res.size())
            res = s.substr(i-j, j*2+1);

        if (i < s.size()-1) 
        {
            j = 0;
            while (i-j >= 0 && i+1+j < s.size() && s[i-j] == s[i+1+j])
                ++j;
            --j;
            if (j*2+2 > res.size())
                res = s.substr(i-j, j*2+2);
        }
    }
    return res;

    }
};


