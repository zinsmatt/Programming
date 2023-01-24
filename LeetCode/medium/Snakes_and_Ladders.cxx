class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> min_moves(1+n*n, std::numeric_limits<int>::max());
        min_moves[1] = 0;

        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            auto x = q.front();
            q.pop();

            for (int i = 1; i <= 6 && i + x <= n*n; ++i) {
                int t = i+x;

                int row = (t - 1) / n;
                int col = (t - 1) % n;
                if (row % 2 == 1)
                    col = n-1-col;
                row = n-1-row;
                if (board[row][col] != -1)
                    t = board[row][col];

                if (t == n*n) {
                    return min_moves[x] + 1;
                }
                if (min_moves[x]+1 < min_moves[t]) {
                    min_moves[t] = min_moves[x] + 1;
                    q.push(t);
                }
            }
        }
        return -1;
    }
};
