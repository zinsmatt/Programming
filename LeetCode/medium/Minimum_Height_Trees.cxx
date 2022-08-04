class Solution {
 
    
    
    
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n, unordered_set<int>());
        for (auto & e : edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        
        
        std::queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (g[i].size() == 1)
                leaves.push(i);
        }
        
        vector<bool> explored(n, false);
        int remaining = n;
        while (remaining > 2) {
            remaining -= leaves.size();
            std::queue<int> new_leaves;
            while (!leaves.empty()) {
                auto x = leaves.front();
                explored[x] = true;
                leaves.pop();
                for (auto e : g[x]) {
                    g[e].erase(x);
                    if (g[e].size() == 1)
                        new_leaves.push(e);
                }
            }
            leaves = std::move(new_leaves);
        }
        vector<int> res;
        for (int i = 0; i < explored.size(); ++i) {
            if (!explored[i]) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
