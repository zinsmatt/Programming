class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int e = nums.size()-1;
        int l = 0, r = nums.size()-1;
        while (l <= r)
        {
            if (std::abs(nums[l]) > std::abs(nums[r]))
            {
                res[e--] = std::pow(nums[l], 2);
                ++l;
            }
            else
            {
                res[e--] = std::pow(nums[r], 2);
                --r;
            }
        }
        
        return res;
    }
};
