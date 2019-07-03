class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        int a = 0, b = nums.size() - 1;
        while (a < b)
        {
            
            int m = (a+b) / 2;
            //std::cout << "a b m " << a << " " << b << " " << m << std::endl;
            if (nums[m] == target)
                return m;
            int good_side;
            if (nums[m] >= nums[a])
                good_side = 0;
            else
                good_side = 1;
            
            if (good_side == 0)
            {
                if (target < nums[m] && target >= nums[a])
                {
                    b = m - 1;
                }
                else
                {
                    a = m + 1;
                }
            }
            else
            {
                if (target <= nums[b] && target > nums[m])
                {
                    a = m + 1;
                }
                else
                {
                    b = m - 1;
                }
            }
        }
        if (a >= 0 && a < nums.size() && nums[a] == target)
        {
            return a;
        } else if (b >= 0 && b < nums.size() && nums[b] == target)
        {
            return b;
        }
        return -1;
        
    }
};