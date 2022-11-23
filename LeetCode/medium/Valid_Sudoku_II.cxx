class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            vector<bool> vh(10, false);
            vector<bool> vv(10, false);
            for (int k = 0; k < 9; ++k) {
                if (board[i][k] != '.') {
                    int x = board[i][k] - '0';
                    if (vh[x])
                        return false;
                    else
                        vh[x] = true;
                }
                if (board[k][i] != '.') {
                    int x = board[k][i] - '0';
                    if (vv[x])
                        return false;
                    else
                        vv[x] = true;
                }
            }
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                vector<bool> v(10, false);
                for (int ii = 0; ii < 3; ++ii) {
                    for (int jj = 0; jj < 3; ++jj) {
                        char c = board[i*3+ii][j*3+jj];
                        if (c != '.') {
                            int x = c - '0';
                            if (v[x])
                                return false;
                            else
                                v[x] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};
