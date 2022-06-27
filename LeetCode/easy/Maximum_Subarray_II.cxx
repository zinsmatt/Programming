class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int best = std::numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); ++i) {
            cur += nums[i];
            best = std::max(best, cur);
            cur = std::max(cur, 0);
        }
        return best;
    }
};
