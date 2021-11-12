const int T = 99999999;
class Solution {
public:

        
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), T));
        
        queue<vector<int>> q;
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[0].size(); ++j)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j, 0});
                        
                }
            }
        }
                
        
        while (!q.empty())
        {
            auto r = q.front();
            auto ii = r[0];
            auto jj = r[1];
            auto d = r[2];
            q.pop();
            
            if (res[ii][jj] != T)
            {
                continue;                
            }
            
            res[ii][jj] = d;
            if (ii > 0)
            {
                q.push({ii-1, jj, d+1});
            }
            if (jj > 0)
            {
                q.push({ii, jj-1, d+1});
            }
            
            if (ii < mat.size()-1)
            {
                q.push({ii+1, jj, d+1});
            }
            if (jj < mat[0].size()-1)
            {
                q.push({ii, jj+1, d+1});
            }
        }
     
        return res;
    }
};
