class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i)
        {
            std::vector<int> occur(9, 0);
            for (auto c : board[i])
            {
                if (c != '.')
                {
                    if (occur[c-'1'] > 0)
                        return false;
                    occur[c-'1'] += 1;
                }
            }
        }
        
        
        for (int i = 0; i < 9; ++i)
        {
            std::vector<int> occur(9, 0);
            for (int j = 0; j < 9; ++j)
            {
                char c = board[j][i];
                if (c != '.')
                {
                    if (occur[c-'1'] > 0)
                        return false;
                    occur[c-'1'] += 1;
                }
            }
        }
        
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                std::vector<int> occur(9, 0);
                for (int ii = 0; ii < 3; ++ii)
                {
                    for (int jj = 0; jj < 3; ++jj)
                    {
                        char c = board[i*3+ii][j*3+jj];
                        if (c != '.')
                        {
                            if (occur[c-'1'] > 0)
                                return false;
                            occur[c-'1'] += 1;
                        }
                    }
                }
            }
        }
        return true;
    }

};