class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = 0, r = 0;
        int res = std::numeric_limits<int>::min();

        while (l < nums.size())
        {
            int s = 0;
            while (r < nums.size() && s >= 0)
            {
                s += nums[r];
                res = std::max(res, s);
                ++r;
            }
            l = r;
            r = l;
        }
        return res;
    }
};
