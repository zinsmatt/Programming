class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1)
            return true;
        int max = 0;
        int i = 0;
        while (max < nums.size()-1)
        {
            max = std::max(max, nums[i] + i);
            if (i < max)
                ++i;
            else
                break;
        }
        return max >= nums.size() - 1;    
    }
};