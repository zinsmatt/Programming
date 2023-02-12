class Solution {
    long long res = 0;
    vector<vector<int>> edges;
    long long solve(int x, int seats, vector<bool>& done) {
        done[x] = true;
        long long total = 1;
        for (auto e : edges[x]) {
            if (!done[e]) {
                long long n = solve(e, seats, done);
                res += n/seats + static_cast<long long>(n%seats != 0);
                total += n;
            }
        }
        return total;
    }

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        edges.resize(n);
        for (auto& r : roads) {
            edges[r[0]].push_back(r[1]);
            edges[r[1]].push_back(r[0]);
        }
        vector<bool> done(n, false);

        solve(0, seats, done);
        return res;
    }
};
