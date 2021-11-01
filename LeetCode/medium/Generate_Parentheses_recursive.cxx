class Solution {
    vector<string> res;
public:
    void solve(string s, int n, int a, int b)
    {
        if (s.size() == n*2)
        {
            res.push_back(s);
        }
        else
        {
            if (a < n)
            {
                solve(s+"(", n, a+1, b);
            }
            if (a > b)
            {
                solve(s+")", n, a, b+1);
            }
        }
        
    }
    vector<string> generateParenthesis(int n) {
        solve("", n, 0, 0);
        
        return res;
    }
};
