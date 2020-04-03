class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums.front();
        int cur = 0;
        for (auto x : nums)
        {
            if (cur + x > x)
            {
                cur += x;
            }
            else
            {
                cur = x;
            }
            res = std::max(res, cur);
        }
        return res;
    }
};
