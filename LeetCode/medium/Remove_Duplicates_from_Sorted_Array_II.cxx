class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        int a = 0, i = 0;
        while (i < nums.size())
        {
            int prev = nums[i];
            int c = 0;
            while (i < nums.size() && nums[i] == prev)
            {
                if (c < 2)
                {
                    nums[a++] = nums[i];
                    ++c;
                }
                ++i;
            }
        }
        return a;
    }
};