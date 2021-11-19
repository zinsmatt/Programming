class Solution {
    int res = 0;
    void solve(int n, int x, vector<bool>& done, vector<vector<int>>& poss)
    {
        if (x == n+1)
        {
            res++;
        }
        else
        {
            for (auto p : poss[x-1])
            {
                if (!done[p-1])
                {
                    done[p-1] = 1;
                    solve(n, x+1, done, poss);
                    done[p-1] = 0;
                }
            }
            
        }
        
    }
    
    
public:
    int countArrangement(int n) {
        vector<vector<int>> p(n, vector<int>());
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i % j == 0 || j % i == 0)
                {
                    p[i-1].push_back(j);
                }
            }
        }
        vector<bool> done(n, false);
        solve(n, 1, done, p);
        return res;
        
    }
};
