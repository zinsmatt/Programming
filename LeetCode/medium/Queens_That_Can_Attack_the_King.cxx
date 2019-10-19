class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;
        vector<bool> q(8*8, false);
        for (auto& p : queens)
        {
            q[p[0]*8+p[1]] = true;
        }
        
        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                if (dx == 0 && dy == 0)
                    continue;
                for (int r = 1; r < 8; ++r)
                {
                    int x = king[0] + r * dx;
                    int y = king[1] + r * dy;
                    if (!isInside(x, y))
                    {
                        break;
                    }
                    else if (q[x*8+y] == true)
                    {
                        res.push_back({x, y});
                        break;
                    }
                }
            }
        }
        return res;
    }
    
    bool isInside(int x, int y)
    {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }
};