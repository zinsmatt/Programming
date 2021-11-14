class Solution {
    
    vector<vector<int>> res;
    void solve(int n, int k, vector<int> cur)
    {
        if (k == 0)
        {
            res.push_back(cur);
        }
        else
        {
            int last = 0;
            if (cur.size()) last = cur.back();
            for (int i = last + 1; i <= n; ++i)
            {
                auto c = cur;
                c.push_back(i);
                solve(n, k-1, c);
            }
        }
    }
    

    
public:
    vector<vector<int>> combine(int n, int k) {
        solve(n, k, {});
        return res;
  
    }
};
