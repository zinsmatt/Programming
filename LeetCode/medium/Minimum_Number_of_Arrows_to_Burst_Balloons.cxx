class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int res = 0;
        int l = points[0][0];
        int r = points[0][1];
        for (auto &v : points) {
            // std::cout << v[0] << " " << v[1] << "\n";
            // std::cout << "lr = " << l << " " << r << "\n";
            if (v[0] > r || v[1] < l) {
                // no intersect
                // cout << "no intersect !!!!\n";
                ++res;
                l = v[0];
                r = v[1];
                continue;
            }

            l = max(l, v[0]);
            r = min(r, v[1]);
            // cout << "new lr " << l << " " << r << "\n";
        }
        ++res;
        
        return res;
    }
};
