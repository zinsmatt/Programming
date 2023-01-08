

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 2)
            return 2;
        else if (points.size() == 1)
            return 1;

        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<double, int> m;
            for (int j = 0; j < points.size(); ++j) {
                if (i != j) {
                    double a = std::atan2(static_cast<double>(points[j][1] - points[i][1]), static_cast<double>(points[j][0]-points[i][0]));
                    if (m.find(a) == m.end()) {
                        m[a] = 1;
                    } else {
                        m[a]++;
                    }
                    res = max(res, m[a]);
                }
            }
        }
        return res + 1;
    }
};
