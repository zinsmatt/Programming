class Solution {
    
    vector<int> choose_pivot(vector<vector<int>>& arr, int l, int r) {
        return arr[(l + r) / 2];
    }
    double dist(vector<int> p) {
        return p[0]*p[0]+p[1]*p[1];
    }
    
    int partition(vector<vector<int>>& points, int l, int r) {
        vector<int> pivot = choose_pivot(points, l, r);
        double p_dist = dist(pivot);
        
        while (l < r) {
            if (dist(points[l]) >= p_dist) {
                std::swap(points[l], points[r]);
                --r;
            } else {
                ++l;
            }
        }
        if (dist(points[l]) < p_dist)
            ++l;
        return l;
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;

        int l = 0, r = points.size()-1;
        int p = points.size();
        while (p != k) {
            p = partition(points, l, r);
            if (p < k) {
                l = p;
            } else {
                r = p-1;
            }
        }
     
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
};
