class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r, c;
        vector<vector<int>> pos(8, vector<int>());
        vector<vector<int>> vert(8, vector<int>());
        for (int i =0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == 'R')
                {
                    r = i;
                    c = j;
                } else if (board[i][j] == 'p')
                {
                    pos[i].push_back(j);
                    vert[j].push_back(i);
                }
            }
        }
        
        int res = 0;
        for (int d = -1; d <= 1; d += 2)
        {
            int i = 1;
            while (1)
            {
                if (!isIn(r+d*i, c) || board[r+d*i][c] == 'B')
                    break;
                if (board[r+d*i][c] == 'p')
                {
                    ++res;
                    break;
                }
                ++i;
            }
        }
        for (int d = -1; d <= 1; d += 2)
        {
            int i = 1;
            while (1)
            {
                if (!isIn(r, c+d*i) || board[r][c+d*i] == 'B')
                    break;
                if (board[r][c+d*i] == 'p')
                {
                    ++res;
                    break;
                }
                ++i;
            }
        }
        return res;
    }
    
    bool isIn(int y, int x)
    {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }
};