class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dists(n, vector<int>(n, numeric_limits<int>::max()));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dists[i][j] = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto [u, v] = q.front();
                        int d = dists[u][v];
                        q.pop();

                        if (u > 0) {
                            if (grid[u-1][v] == 0 && dists[u-1][v] > d+1) {
                                dists[u-1][v] = d+1;
                                q.push({u-1, v});
                            }
                        }
                        if (u < n-1) {
                            if (grid[u+1][v] == 0 && dists[u+1][v] > d+1) {
                                dists[u+1][v] = d+1;
                                q.push({u+1, v});
                            }
                        }

                        if (v > 0) {
                            if (grid[u][v-1] == 0 && dists[u][v-1] > d+1) {
                                dists[u][v-1] = d+1;
                                q.push({u, v-1});
                            }
                        }
                        if (v < n-1) {
                            if (grid[u][v+1] == 0 && dists[u][v+1] > d+1) {
                                dists[u][v+1] = d+1;
                                q.push({u, v+1});
                            }
                        }
                    }
                }
            }
        }


        int res = -1;
        for (auto &v : dists) {
            for (auto x : v)
                if (x > 0 && x < numeric_limits<int>::max())
                    res = max(res, x);
        }
        return res;
        
    }
};
