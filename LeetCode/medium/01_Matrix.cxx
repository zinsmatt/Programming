class Solution {
public:
    
    void spread(const vector<vector<int>> mat, int i, int j, vector<vector<int>>& g, int v)
    {
        g[i][j] = std::min(g[i][j], v);
        
        if (i > 0 && mat[i-1][j] && g[i-1][j] > v)
        {
            spread(mat, i-1, j, g, v+1);
        }
        if (j > 0 && mat[i][j-1] && g[i][j-1] > v)
        {
            spread(mat, i, j-1, g, v+1);
        }
        
        if (i < mat.size()-1 && mat[i+1][j] && g[i+1][j] > v)
        {
            spread(mat, i+1, j, g, v+1);
        }
        if (j < mat.front().size()-1 && mat[i][j+1] && g[i][j+1] > v)
        {
            spread(mat, i, j+1, g, v+1);
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {       
        
        int m = mat.size();
        int n = mat.front().size();
        vector<vector<int>> g(m, vector<int>(n, std::numeric_limits<int>::max()));
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 0)
                {
                    spread(mat, i, j, g, 0);    
                }
            }
        }
        return g;
    }
};
