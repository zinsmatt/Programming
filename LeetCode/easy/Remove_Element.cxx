class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int l = 0, r = nums.size() - 1;
        
        while (l <= r)
        {
            while (l < nums.size() && nums[l] != val)
                ++l;
            while (r >= 0 && nums[r] == val)
                --r;
            if (l < nums.size() && r >= 0 && l <= r)
            {
                swap(nums[l], nums[r]);
                ++l;
                --r;
            }
            
        }
        return l;
    }
};