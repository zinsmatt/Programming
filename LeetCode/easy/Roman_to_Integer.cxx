class Solution {
public:
    int romanToInt(string s) {
        reverse(s.begin(), s.end());
        int i = 0;
        int res = 0;
        while (i < s.size())
        {
            switch (s[i])
            {
                case 'M':
                    res += 1000;
                    break;
                case 'D':
                    res += 500;
                    break;
                case 'C':
                    if (i > 0 && (s[i-1] == 'D' || s[i-1] == 'M'))
                        res -= 100;
                    else
                        res += 100;
                    break;
                case 'L':
                    res += 50;
                    break;
                case 'X':
                    if (i > 0 && (s[i-1] == 'L' || s[i-1] == 'C'))
                        res -= 10;
                    else
                        res += 10;
                    break;
                case 'V':
                    res += 5;
                    break;
                case 'I':
                    if (i > 0 && (s[i-1] == 'V' || s[i-1] == 'X'))
                        res -= 1;
                    else
                        res += 1;
                    break;
            }
            ++i;
        }
        
        return res;
    }
};
