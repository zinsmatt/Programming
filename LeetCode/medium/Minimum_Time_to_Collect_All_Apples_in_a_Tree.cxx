class Solution {

    int solve(int x, int s, const vector<vector<int>>& edges, const vector<bool>& apple, vector<bool>& done) {
        int s_init = s;
        done[x] = true;
        // cout << "call " << x << " " << s << "\n";
        for (auto e : edges[x]) {
            if (!done[e])
                s = solve(e, s+1, edges, apple, done);
            // cout << "ret s = " << s << "\n";
        }

        if (x == 0)
            return s;

        if (apple[x] || s != s_init)
            return s+1;
        else
            return s-1;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> e(n, vector<int>());
        for (auto &p: edges) {
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }
        vector<bool> done(n, false);
        return solve(0, 0, e, hasApple, done);    
    }
};
