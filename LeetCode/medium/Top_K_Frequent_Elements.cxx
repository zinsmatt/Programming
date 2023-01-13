class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto x : nums) {
            ++m[x];
        }
        vector<pair<int, int>> r;
        for (auto p : m)
            r.push_back(p);
        sort(r.begin(), r.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        vector<int> res(k);
        for (int i = 0; i < k; ++i)
            res[i] = r[i].first;
        return res;
    }
};
