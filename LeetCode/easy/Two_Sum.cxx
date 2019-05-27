class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> indices(nums.size());
        std::iota(indices.begin(), indices.end(), 0);
        std::sort(indices.begin(), indices.end(), [&nums](int a, int b) {
            return nums[a] < nums[b];
        });
        std::sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while (1) // because it assumed that a solution exists
        {
            int s = nums[l] + nums[r];
            if (s == target)
                break;
            else if (s < target)
            {
                l++;
            }
            else
            {
                r--;                
            }
        }
        
        std::vector<int> res = {indices[l], indices[r]};
        return res;
    }
};