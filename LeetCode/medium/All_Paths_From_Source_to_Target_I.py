class Solution {
    vector<vector<int>> res;
    void solve(vector<vector<int>>& g, int x, int t, vector<int> cur)
    {
        if (x == t)
        {
            res.push_back(cur);
        }
        for (auto e : g[x])
        {
            auto c = cur;
            c.push_back(e);
            solve(g, e, t, c);
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        solve(graph, 0, graph.size()-1, {0});
        return res;
    }
};
