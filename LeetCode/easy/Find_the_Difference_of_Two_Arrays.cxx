class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> s1, s2, r1, r2;
        std::vector<vector<int>> res(2, vector<int>());

        for (auto x : nums1)
            s1.insert(x);
        for (auto x : nums2)
            s2.insert(x);
        for (auto x : nums1)
            if (s2.count(x) == 0 && r1.count(x) == 0) {
                res[0].push_back(x);
                r1.insert(x);
            }
        for (auto x : nums2)
            if (s1.count(x) == 0 && r2.count(x) == 0) {
                res[1].push_back(x);
                r2.insert(x);
            }
        return res;
        
    }
};
