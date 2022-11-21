class Solution {
    vector<pair<int, int>> frees;
    vector<vector<char>> new_board;

    void solve(vector<pair<int, int>>& frees, int k, vector<vector<char>>& m) {
        // std::cout << "solve " << frees[k].first << " " << frees[k].second << endl;
        if (k < frees.size()) {
            for (int i = 1; i <= 9; ++i) {
                // std::cout << "try " << i << "\n";
                if (check(frees[k].first, frees[k].second, m, '0' + i)) {
                    m[frees[k].first][frees[k].second] = '0' + i;
                    solve(frees, k+1, m);
                    m[frees[k].first][frees[k].second] = '.';
                }
            }
        } else
        {
            new_board = m;
        }
    }

    bool check(int i, int j, vector<vector<char>>& m, char x) {
        // cout << "check " << i << " " << j << "!!! \n";
        for (int k = 0; k < 9; ++k) {
            if (m[k][j] == x || m[i][k] == x)
                return false;
        }
        int ii = i / 3;
        int jj = j / 3;
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                if (m[ii*3+k][jj*3+l] == x)
                    return false;
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    frees.push_back({i, j});
            }
        }

        solve(frees, 0, board);
        board = new_board;
    }
};
