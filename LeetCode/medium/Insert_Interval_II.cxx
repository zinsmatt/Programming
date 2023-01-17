class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> before;
        vector<vector<int>> after;
        int a = newInterval[0];
        int b = newInterval[1];

        for (auto &v : intervals) {
            if (v[1] < newInterval[0]) {
                before.push_back(v);
            } else if (v[0] > newInterval[1]) {
                after.push_back(v);
            } else {
                a = min(a, v[0]);
                b = max(b, v[1]);
            }
        }
        vector<vector<int>> res;
        res.insert(res.end(), before.begin(), before.end());
        res.push_back({a, b});
        res.insert(res.end(), after.begin(), after.end());
        return res;        
    }
};
