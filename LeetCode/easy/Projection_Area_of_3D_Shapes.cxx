class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        const int N = grid.size();
        int xy = 0, horiz = 0, vert = 0;
        vector<int> maxes(N, 0);
        for (int i = 0; i < N; ++i)
        {
            horiz += *max_element(grid[i].begin(), grid[i].end());
            for (int j = 0; j < N; ++j)
            {
                maxes[j] = std::max(maxes[j], grid[i][j]);
                if (grid[i][j] > 0)
                    ++xy;
            }
        }
        vert += std::accumulate(maxes.begin(), maxes.end(), 0);
        return xy + horiz + vert;
    }
};