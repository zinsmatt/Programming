class Solution {
  
        
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        
        vector<vector<int>> g(n, vector<int>(n, 1));
        
        for (auto& v : mines)
        {
            g[v[0]][v[1]] = 0;
        }
        
        
        vector<vector<int>> hl(n, vector<int>(n, 0));
        vector<vector<int>> hr(n, vector<int>(n, 0));
        vector<vector<int>> vt(n, vector<int>(n, 0));
        vector<vector<int>> vb(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            int m = 0;
            for (int j = 0; j < n; ++j)
            {
                if (g[i][j])
                {
                    m++;
                }
                else
                {
                    m = 0;
                }
                hl[i][j] = m;
            }
            
            int mm = 0;
            for (int j = n-1; j >= 0; --j)
            {
                if (g[i][j])
                {
                    mm++;
                } else {
                    mm = 0;
                }
                hr[i][j] = mm;
            }
        }
        
        
        for (int i = 0; i < n; ++i)
        {
            int m = 0;
            for (int j = 0; j < n; ++j)
            {
                if (g[j][i])
                {
                    m++;
                }
                else
                {
                    m = 0;
                }
                vt[j][i] = m;
            }
            
            int mm = 0;
            for (int j = n-1; j >= 0; --j)
            {
                if (g[j][i])
                {
                    mm++;
                } else {
                    mm = 0;
                }
                vb[j][i] = mm;
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                res = max(res, min(min(hl[i][j], hr[i][j]), min(vt[i][j], vb[i][j])));
            }
        }
        
        return res;
    }
};
