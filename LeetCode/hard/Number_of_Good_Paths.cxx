class Solution {
    vector<int> parents;
    vector<int> ranks;

    int find(int x) {
        if (parents[x] == -1)
            return x;
        else
            return find(parents[x]);
    }

    void f_union(int a, int b) {
        auto ra = find(a);
        auto rb = find(b);
        if (ra != rb) {
            if (ranks[ra] < ranks[rb])
                parents[ra] = rb;
            else {
                parents[rb] = ra;
                if (ranks[ra] == ranks[rb]) {
                    ranks[ra]++;
                }
            }
        }
    }

   
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        vector<vector<int>> adj(vals.size(), vector<int>());
        for (auto &g : edges) {
            adj[g[0]].push_back(g[1]);
            adj[g[1]].push_back(g[0]);
        }
        
        unordered_map<int, vector<int>> nodes;
        vector<int> values;
        for (int i = 0; i < vals.size(); ++i) {
            auto x = vals[i];
            if (nodes.count(x))
                nodes[x].push_back(i);
            else {
                nodes[x] = {i};
                values.push_back(x);
            }
        }
        sort(values.begin(), values.end());

        parents.resize(vals.size(), -1);
        ranks.resize(vals.size(), 0);
        int res = 0;
        for (auto v : values) {
            for (auto n : nodes[v]) {
                for (auto e : adj[n]) {
                    std::cout << e << endl;
                    if (vals[e] <= v) {
                        f_union(n, e);
                    }
                }
            }

            unordered_map<int, int> count;
            for (auto n : nodes[v]) {
                count[find(n)]++;
            }

            for (auto &p : count) {
                res += (p.second * (p.second+1)) / 2;
            }
        }



        return res;
    }
};
