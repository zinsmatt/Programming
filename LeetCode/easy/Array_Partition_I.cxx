class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(std::begin(nums), std::end(nums));
        int res = 0;
        for (int i = 0; i < nums.size(); i+=2)
            res += nums[i];
        return res;
    }
};