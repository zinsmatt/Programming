class Solution {
public:
    
    void toggle_row(vector<vector<int>>& A, int r)
    {
        std::transform(A[r].begin(), A[r].end(), A[r].begin(), [](int x) { return !x; });
    }
    void toggle_col(vector<vector<int>>& A, int c)
    {
        for (int i = 0; i < A.size(); ++i)
        {
            A[i][c] = !A[i][c];
        }
        
    }
    int final(vector<vector<int>> &A)
    {
        int r = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            
            for (int j = 0; j < A[i].size(); ++j)
            {
                if (A[i][j])
                    r += pow(2, A[i].size()-1-j);
            }
        }
        return r;
    }
    
    
    int matrixScore(vector<vector<int>>& A) {
        
        auto A_init = A;
        // rows first
        for (int i = 0; i < A.size(); ++i)
        {
            if (!A[i][0]) toggle_row(A, i);
        }
        for (int i = 1; i < A[0].size(); ++i)
        {
            int s = 0;
            for (int j = 0; j < A.size(); ++j) s+=A[j][i];
            if (s < A.size()-s) toggle_col(A, i);
        }
        
        auto r1 = final(A);
        
        A = A_init;
        toggle_col(A, 0);
        for (int i = 0; i < A.size(); ++i)
        {
            if (!A[i][0]) toggle_row(A, i);
        }
        for (int i = 1; i < A[0].size(); ++i)
        {
            int s = 0;
            for (int j = 0; j < A.size(); ++j) s+=A[j][i];
            if (s < A.size()-s) toggle_col(A, i);
        }
        auto r2 = final(A);
        
        return max(r1, r2);
        
    }
};
