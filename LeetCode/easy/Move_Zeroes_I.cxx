class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int a = 0;
        int i = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[a++] = nums[i];
            }
        }
        std::fill(nums.begin()+a, nums.end(), 0);
    }
};
