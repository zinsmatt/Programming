class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() <= 4) 
            return 0;
        
        return std::min(std::min(nums[nums.size()-4]-nums[0],
                                 nums[nums.size()-4+1]-nums[1]),
                        std::min(nums[nums.size()-4+2]-nums[2],
                                 nums[nums.size()-4+3]-nums[3]));
    }
};
