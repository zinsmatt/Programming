class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        for (int i = 0; i < board.size(); ++i)
        {
            int j = 0;
            //std::cout << std::endl;
            while (j < board[0].size())
            {
                //std::cout << board[i][j] << " ";
                if (board[i][j] == '0')
                {
                    if (i < board.size() - 1)
                    {
                        if (board[i+1][j] == 'X')
                            board[i+1][j] = '0';
                    }
                }
                else if (board[i][j] == 'X')
                {
                    if (j < board[0].size() - 1)
                    {
                        res++;
                        if (board[i][j+1] == 'X')
                        {
                            while ( j < board[0].size() && board[i][j] == 'X')
                                ++j;
                        }
                        else
                        {
                            if (i < board.size() - 1 && board[i+1][j] == 'X')
                                board[i+1][j] = '0';
                        }
                    }
                    else
                    {
                        res++;
                        if (i < board.size() - 1 && board[i+1][j] == 'X')
                            board[i+1][j] = '0';
                    }
                }
                ++j;
            }
        }
        return res;
    }
};