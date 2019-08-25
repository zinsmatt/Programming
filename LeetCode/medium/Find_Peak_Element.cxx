class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        else if (nums.size() == 1)
        {
            return 0;
        }

        int i = 0;
        long int a = -9999999999999;
        long int b = nums[i];
        long int c = nums[i+1];
        while (b <= a || b <= c)
        {
            a = b;
            b = c;
            if (i+2>=nums.size())
                c = -9999999999999;
            else
                c = nums[i+2];
            ++i;
        }
        return i;
    }
};