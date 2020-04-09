class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        string res_s(S.size(), ' ');
        string res_t(T.size(), ' ');
        int a = 0;
        
        int s = S.size()-1;
        int skip_s = 0;
        while (s >= 0)
        {
            if (S[s] == '#')
                skip_s++;
            else
            {
                if (skip_s == 0)
                {
                    res_s[a++] = S[s];
                }
                else
                    skip_s--;
            }
            --s;
        }
        res_s = res_s.substr(0, a);
        
        int t = T.size()-1;
        int skip_t = 0;
        a = 0;
        while (t >= 0)
        {
            if (T[t] == '#')
                skip_t++;
            else
            {
                if (skip_t == 0)
                    res_t[a++] = T[t];
                else
                    skip_t--;
            }
            --t;
        }
        res_t = res_t.substr(0, a);
        
        
        
        return res_s == res_t;
    }
};
