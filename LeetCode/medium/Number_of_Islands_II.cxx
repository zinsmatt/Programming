class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> m(grid.size(), vector<int>(grid[0].size(), -1));
        int count = 0;
        for (int i = 0; i < m.size(); ++i)
        {
            for (int j = 0; j < m[0].size(); ++j)
            {
                if (m[i][j] != -1 || grid[i][j] == '0')
                    continue;

                // BFS with value count
                std::queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    auto [u, v] = q.front();
                    q.pop();
                    if (m[u][v] != -1)
                        continue;
                    m[u][v] = count;
                    if (u > 0 && grid[u-1][v] == '1' && m[u-1][v] == -1)
                        q.push({u-1, v});
                    if (u < grid.size()-1 && grid[u+1][v] == '1'  && m[u+1][v] == -1)
                        q.push({u+1, v});
                    if (v > 0 && grid[u][v-1] == '1' && m[u][v-1] == -1)
                        q.push({u, v-1});
                    if (v < grid[0].size()-1 && grid[u][v+1] == '1' && m[u][v+1] == -1)
                        q.push({u, v+1});
                }
                ++count;
            }
        }
        return count;
    }
};



