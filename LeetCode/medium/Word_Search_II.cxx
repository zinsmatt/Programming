class Solution {
    bool solve(vector<vector<char>>& g, int i, int j, string& w, int k) {

        if (i < 0 || i >= g.size() || j < 0 || j >= g[0].size())
            return false;

        if (w[k] != g[i][j])
            return false;

        if (k == w.size()-1)
            return true;

        g[i][j] = '-';
        bool t = solve(g, i-1, j, w, k+1);
        bool b = solve(g, i+1, j, w, k+1);
        bool l = solve(g, i, j-1, w, k+1);
        bool r = solve(g, i, j+1, w, k+1);
        g[i][j] = w[k];
        return t || b || l || r;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (solve(board, i, j, word, 0))
                return true;
            }
        }
        return false;
    }
};
