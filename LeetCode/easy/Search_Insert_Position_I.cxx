class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        long l = 0, r = nums.size()-1;
        while (l < r)
        {
            long m = (l+r) / 2;
            if (nums[m] < target)
            {
                l = m+1;
            }
            else
            {
                r = m;
            }
        }
        if (nums[l] < target)
            return l+1;
        else
            return l;
    }
};
