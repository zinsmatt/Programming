class Solution {
    vector<int> memo;
    int solve(const std::string& s, int l)
    {
        if (l < s.size())
        {
            if (memo[l] != -1)
                return memo[l];

            int i = l;
            int r = 0;

            if (s[l] == '0')
            {
                memo[l] = 0;
                return 0;
            }
            
            r += solve(s, l+1);
            
            
           if (l < s.size()-1 && (s[l] == '1' && s[l+1] >= '0' || s[l] == '2' && s[l+1] >= '0' && s[l+1] <= '6'))
            {
                r += solve(s, l+2);
            }

            memo[l] = r;
            return r;
        }
        return 1;
    }
public:
    int numDecodings(string s) {
        memo.resize(s.size(), -1);
        return solve(s, 0);
    }
};       

