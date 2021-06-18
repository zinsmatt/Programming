class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i  = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res = std::max(res, nums[i]+nums[nums.size()-1-i]);            
        }
        return res;
    }
};
