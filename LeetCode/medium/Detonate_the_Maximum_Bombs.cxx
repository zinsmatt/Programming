class Solution {
    int expand(vector<vector<int>>& g, int i, vector<bool>& done) 
    {
        done[i] = true;
        int res = 1;
        for (auto j : g[i]) {
            if (!done[j]) {
                res += expand(g, j, done);
            }
        }
        return res;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> g(bombs.size());
        for (int i = 0; i < bombs.size(); ++i) {
            long long r = bombs[i][2];
            long long rr = r * r;
            long long x = bombs[i][0];
            long long y = bombs[i][1];
            for (int j = 0; j < bombs.size(); ++j) {
                if (i != j) {
                    if (pow(x-bombs[j][0], 2) + pow(y-bombs[j][1], 2) <= rr) {
                        g[i].push_back(j);
                    }
                }
            }
        }

        int res = 0;
        for (int i = 0; i < bombs.size(); ++i) {
            vector<bool> done(bombs.size(), false);
            res = max(res, expand(g, i, done));
        }
        return res;
    }
};
