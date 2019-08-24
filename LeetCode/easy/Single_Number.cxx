class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto k : nums)
        {
            res = res ^ k;
        }
        return res;
    }
};