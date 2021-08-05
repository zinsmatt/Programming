class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        std::vector<std::vector<int>> m(n+2, vector<int>(n+2, 0));
        
        for (int s = 1; s <= n; ++s)
        {
            for (int i = 1; i < (int)n+1-s; ++i)
            {
                int j = i + s - 1;
                int turn = (n-s-1) % 2;
                
                if (turn == 0)
                {   // Alex
                
                    m[i][j] = std::max(piles[i-1] + m[i+1][j], piles[j-1] + m[i][j-1]);
                }
                else
                {
                    m[i][j] = std::min(-piles[i-1] + m[i+1][j], -piles[j-1] + m[i][j-1]);
                }
            }
        }
        return m[n-1][n-1] > 0;
    }
};
