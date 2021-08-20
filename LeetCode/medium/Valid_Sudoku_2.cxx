class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i)
        {
            vector<int> row(10, 0);
            vector<int> col(10, 0);
            
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    int x = board[i][j]-'0';
                    if (row[x] > 0) return false;
                    else row[x] = 1;
                }
                if (board[j][i] != '.')
                {
                    int y = board[j][i]-'0';
                    if (col[y] > 0) return false;
                    else col[y] = 1;
                }
            }
        }
        for (int ii = 0; ii < 3; ++ii)
        {
            for (int jj = 0; jj < 3; ++jj)
            {
                vector<int> sq(10, 0);
                for (int i = 0; i < 3; ++i)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        if (board[ii*3+i][jj*3+j] == '.')
                            continue;
                        int x = board[ii*3+i][jj*3+j]-'0';
                        if (sq[x] > 0) return false;
                        else sq[x] = 1;
                    }
                }
            }
        }
        return true;
    }
};
