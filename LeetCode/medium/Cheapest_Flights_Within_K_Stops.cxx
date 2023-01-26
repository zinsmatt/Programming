class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int T = 101;
        vector<vector<int>> costs(n, vector<int>(T+5, numeric_limits<int>::max()));

        vector<vector<pair<int, int>>> g(n);
        for (auto& f : flights) {
            g[f[0]].push_back({f[1], f[2]});
        }

        queue<pair<int, int>> q;
        q.push({src, 0});
        costs[src][0] = 0;

        while (!q.empty()) {
            auto [x, nb] = q.front();
            q.pop();

            for (auto [e, c] : g[x]) {
                bool change = false;
                for (int i = nb; i < min(T-1, k+2); ++i) {
                    if (costs[x][i] < std::numeric_limits<int>::max()) {
                        if (costs[e][i+1] > costs[x][i]+c) {
                            change = true;
                            costs[e][i+1] = costs[x][i] + c;
                        }
                    }
                }
                if (change)
                    q.push({e, nb+1});
            }
        }

        auto res = *std::min_element(costs[dst].begin(), costs[dst].begin()+2+k);
        if (res == std::numeric_limits<int>::max())
            res = -1;
        return res;

    }
};
