class Solution {
    int d_manh(const vector<int>& a, const vector<int>& b) {
        return std::abs(a[0] - b[0]) + std::abs(a[1] - b[1]);
    }
    
    vector<int> parents;
    vector<int> rangs;
    
    int find(int x) {
        if (parents[x] == -1)
            return x;
        parents[x] = find(parents[x]);
        return parents[x];
    }
    
    bool f_union(int x, int y) {
        auto px = find(x);
        auto py = find(y);
        // std::cout << "find " << x << " = " << px << std::endl;
        // std::cout << "find " << y << " = " << py << std::endl;
        if (px != py) {
            if (rangs[px] < rangs[py]) {
                parents[px] = py;
            } else {
                parents[py] = px;
                if (rangs[px] == rangs[py]) {
                    rangs[px]++;
                }
            }
            return true;
        }
        return false;
    }
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        std::vector<std::pair<int, std::pair<int, int>>> edges;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i+1; j < points.size(); ++j) {
                edges.push_back({d_manh(points[i], points[j]), {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        parents.resize(points.size(), -1);
        rangs.resize(points.size(), 0);
        
        long long res = 0;
        int count = 0;
        for (int i = 0; i < edges.size() && count + 1 < points.size(); ++i) {
            auto e = edges[i];
            auto x = e.second.first;
            auto y = e.second.second;
//            std::cout << x << " <-> " << y << " = " << e.first << "\n";
            auto ret = f_union(x, y);
            if (ret) {
                res += e.first;
                ++count;
            }
//            std::cout << "res = " << res << "\n";
            
        }
        
        return res;
        
    }
};
