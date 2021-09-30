class Solution {
    
    vector<bool> used;
    
    bool solve(int cur, vector<int>& nums, int idx, int k, int target)
    {
        if (k == 0)
            return true;
        
        
        if (cur > target)
            return false;
        else if (cur == target)
        {
            return solve(0, nums, 0, k-1, target);
        }
        
        
        
        for (int j = idx; j < nums.size(); ++j)
        {
            if (!used[j])
            {
                used[j] = true;
                auto res = solve(cur+nums[j], nums, j+1, k, target);
                if (res) return true;
                used[j] = false;
            }
        }
        return false;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (sum % k != 0)
            return false;
        
        vector<int> v(k, 0);
        used.resize(nums.size(), false);
        
        
        
        return solve(0, nums, 0, k, sum/k);
    }
};
