class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n, numeric_limits<int>::max());
        vector<vector<int>> done(n, vector<int>(2, false));

        vector<vector<int>> reds(n);
        for (auto &p : redEdges) {
            reds[p[0]].push_back(p[1]);
        }
        vector<vector<int>> blues(n);
        for (auto &p : blueEdges) {
            blues[p[0]].push_back(p[1]);
        }

        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0});
        q.push({0, 1, 0});
        res[0] = 0;
        done[0][0] = true;
        done[0][1] = true;

        while (!q.empty()) {
            auto [x, prev, d] = q.front();
            res[x] = min(res[x], d);
            q.pop();

            if (prev == 1) {
                for (auto &e : reds[x]) {
                    if (!done[e][0]) {
                        done[e][0] = true;
                        q.push({e, 0, d+1});
                    }
                }
            }



            if (prev == 0) {
                for (auto &e : blues[x]) {
                    if (!done[e][1]) {
                        done[e][1] = true;
                        q.push({e, 1, d+1});
                    }
                }
            }

        }

        for (auto& x : res)
            if (x == numeric_limits<int>::max())
                x = -1;


        return res;
    }
};
