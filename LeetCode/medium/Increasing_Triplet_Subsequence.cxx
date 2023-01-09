class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<bool> less(nums.size(), false);
        vector<bool> greater(nums.size(), false);
        int vmin = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (vmin < nums[i]) {
                less[i] = true;
            }
            vmin = min(vmin, nums[i]);
        }
        
        int vmax = nums.back();
        for (int i = nums.size()-1; i >= 0; --i) {
            if (vmax > nums[i]) {
                greater[i] = true;
            }
            vmax = max(vmax, nums[i]);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (greater[i] && less[i])
                return true;
        }
        return false;
    }
};
