class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l < r) {
            int m = (l+r) / 2;

            if (target == nums[m])
                return m;

            if (target == nums[l])
                return l;

            if (target == nums[r])
                return r;

            if (nums[m] > nums[l]) {
                //left part linear
                if (target < nums[m] && target > nums[l])
                    r = m-1;
                else
                    l = m+1;
            } else {
                // right part is linear
                if (target > nums[m] && target < nums[r])
                    l = m+1;
                else
                    r = m-1;
            }
        }
        if (nums[l] == target)
            return l;
        return -1;        
    }
};

