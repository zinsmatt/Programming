class Solution {
    
  
    double dist(vector<int> p) {
        return p[0]*p[0]+p[1]*p[1];
    }
  
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<double> dists(points.size(), 0);
        double dmax = 0;
        double dmin = 0;
        std::list<int> indices;
        for (int i = 0; i < points.size(); ++i) {
            dists[i] = dist(points[i]);
            dmax = std::max(dmax, dists[i]);
            indices.push_back(i);
        }
        list<int> less, greater;
        vector<vector<int>> res;

        while (k > 0) {
            double dm = (dmax + dmin) / 2;
            dmax = 0;
            for (auto i : indices) {
                dmax = std::max(dmax, dists[i]);
                if (dists[i] <= dm) {
                    less.push_back(i);
                } else {
                    greater.push_back(i);
                }
            }
            
            if (less.size() <= k) {
                for (auto x : less)
                    res.push_back(points[x]);
                k -= less.size();
                indices = greater;
                greater.clear();
                less.clear();
                
                dmin = dm;
            } else {
                indices = less;
                less.clear();
                dmax = dm;
            }
        }

        return res;
    }
}
