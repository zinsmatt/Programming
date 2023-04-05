class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long prefsum = 0;
        long long res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefsum += nums[i];
            res = max(res, static_cast<long long>(std::ceil(static_cast<double>(prefsum) / (i+1))));
        }

        return res;
    }
};
