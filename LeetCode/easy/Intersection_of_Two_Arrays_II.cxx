class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> count(1001, 0);
        for (auto x : nums1)
            ++count[x];
        vector<int> out;
        for (auto x : nums2) {
            if (count[x] > 0) {
                out.push_back(x);
                --count[x];
            }
        }
        return out;
    }
};
