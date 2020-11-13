class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        
        int H = mat.size(), W = mat[0].size();
        auto S = mat;
        
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (i)
                    S[i][j] += S[i-1][j];
                if (j)
                    S[i][j] += S[i][j-1];                    
                if (i && j)
                    S[i][j] -= S[i-1][j-1];
            }
        }
        for (auto l : S)
        {
            for (auto x : l)
                cout << x << " ";
            cout << "\n";
        }
        
        vector<vector<int>> res(H, vector<int>(W));
        for (int r = 0; r < H; ++r) {
            for (int c = 0; c < W; ++c) {
                int min_r = max(0, r-K);
                int min_c = max(0, c-K);
                int max_r = min(H-1, r+K);
                int max_c = min(W-1, c+K);
                res[r][c] = S[max_r][max_c];
                if (min_r)
                    res[r][c] -= S[min_r-1][max_c];
                if (min_c)
                    res[r][c] -= S[max_r][min_c-1];
                if (min_r && min_c)
                    res[r][c] += S[min_r-1][min_c-1];
            }
        }
       
        return res;         
    }
};
