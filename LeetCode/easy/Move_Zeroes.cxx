class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int next = 0;
        for (auto x: nums)
        {
            if (x != 0)
            {
                nums[next++] = x;
            }
        }
        while (next < nums.size())
            nums[next++] = 0;
    }
};
