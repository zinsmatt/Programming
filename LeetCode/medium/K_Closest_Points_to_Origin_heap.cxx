class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
        };
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        int i = 0; 
        while (i < k) {
            q.push(points[i]);
            ++i;
        }
        
        while (i < points.size()) {
            if (cmp(points[i], q.top())) {
                q.pop();
                q.push(points[i]);
            }
            ++i;
        }
        vector<vector<int>> res;
        while (!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
