class Solution {
    
    bool dfs(vector<vector<char>>& board, int i, int j, const string& w, int k) {
        // std::cout << "cell with " << board[i][j] << " looking for " << w[k] << "\n";
        if (board[i][j] != w[k])
            return false;
        
        if (k == w.size()-1)
            return true;
        board[i][j] = '-';
        if (i > 0)
            if (dfs(board, i-1, j, w, k+1)) return true;
        if (i < board.size()-1)
            if(dfs(board, i+1, j, w, k+1)) return true;
        if (j > 0)
            if(dfs(board, i, j-1, w, k+1)) return true;
        if (j < board[0].size()-1)
            if(dfs(board, i, j+1, w, k+1)) return true;
        board[i][j] = w[k];
        return false;
    }
    
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board.front().size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};
