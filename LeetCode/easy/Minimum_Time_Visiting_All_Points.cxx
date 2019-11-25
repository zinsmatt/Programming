class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if (points.size() == 0)
            return 0;
        vector<int> p = points.front();
        int res = 0;
        for (int i = 1; i < points.size(); ++i)
        {
            const vector<int>& q = points[i];
            int dx = q[0] - p[0];
            int dy = q[1] - p[1];
            
            int mini = min(abs(dx), abs(dy));
            res += mini + max(abs(dx), abs(dy)) - mini;
            
            p[0] = q[0];
            p[1] = q[1];
        }
        return res;
    }
};