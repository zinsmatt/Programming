class Solution {
    const int D = 32;
    vector<string> res;
    void solve(const string& s, int i, string cur)
    {
        if (cur.size() == s.size())
        {
            res.push_back(cur);
        }
        else
        {
            if (s[i] <= '9' && s[i] >= '0')
            {
                solve(s, i+1, cur + s[i]);
            }
            else
            {
                char aa;
                if (s[i] >= 'a' && s[i] <= 'z')
                {
                    aa = s[i]-D;
                }
                else
                {
                    aa = s[i]+D;
                }
                
                solve(s, i+1, cur + s[i]);
                solve(s, i+1, cur + aa);
                
            }
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        solve(s, 0, "");
        return res;
    }
};
