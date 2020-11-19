class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        auto h = matrix.size();
        auto w = matrix[0].size();
            
        vector<vector<int>> S(h, vector<int>(w, 0));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                auto r = matrix[i][j];
                if (i)
                    r += S[i-1][j];
                if (j)
                    r += S[i][j-1];
                if (i && j)
                    r -= S[i-1][j-1];
                S[i][j] = r;
            }
        }
        cout << "onde\n";
        for (auto v : S)
        {
            for (auto x : v)
                cout << x << " ";
           cout << "\n";
        }
        int res = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                int x = min(i, j);
                int d = 1;
                while (d <= 1 + x) {
                    
                    int m = S[i][j];
                    if (i - d >= 0)
                        m -= S[i-d][j];
                    if (j - d >= 0)
                        m -= S[i][j-d];
                    if (i-d >= 0 && j-d >= 0)
                        m += S[i-d][j-d];

                    
//                    cout << i << "  " <<j << " " << d << " = "<< m << "\n";
                    if (m == d*d)
                        ++res;
                    else 
                        break;
                
                    ++d;
                }
            }
        }
        return res;
    }
};
