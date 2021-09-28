class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int o = 1, e = 0;
        vector<int> res(nums.size());
        for (auto x : nums)
        {
            if (x % 2)
            {
                res[o] = x;
                o += 2;
            }
            else
            {
                res[e] = x;
                e += 2;
            }
        }
        return res;
    }
};
