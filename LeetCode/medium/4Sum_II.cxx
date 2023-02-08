class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m12;
        for (auto x : nums1) {
            for (auto y : nums2) {
                m12[x+y]++;
            }
        }
        unordered_map<int, int> m34;
        for (auto x : nums3) {
            for (auto y : nums4) {
                m34[x+y]++;
            }
        }

        long res = 0;
        for (auto p : m12) {
            if (m34.count(-p.first)) {
                res += p.second * m34[-p.first];
            }
        }
        return res;
    }
};
