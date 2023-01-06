class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> b(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int count = 0;
                for (int ii = -1; ii <= 1; ++ii) {
                    int iii = i + ii;
                    if (iii >= 0 && iii < n) {
                        for (int jj = -1; jj <= 1; ++jj) {
                            if (ii != 0 || jj != 0) {
                                int jjj = j + jj;
                                if (jjj >= 0 && jjj < m) {
                                    count += board[iii][jjj];
                                }
                            }
                        }
                    }
                }
                b[i][j] = board[i][j];
                if (board[i][j] == 1) {
                    if (count < 2 || count > 3) {
                        b[i][j] = 0;
                    }
                } else if (board[i][j] == 0 && count == 3) {
                    b[i][j] = 1;
                }
            }
        }
        board = b;
    }
};
