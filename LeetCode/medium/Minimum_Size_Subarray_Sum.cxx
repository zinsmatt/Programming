class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<long long> s(nums.size()+1, 0);
        
        for (int i = 0; i < nums.size(); ++i)
        {
            s[i+1] = nums[i] + s[i];
        }
   
        
        for (int n = 1; n <= nums.size(); ++n)
        {
            for (int i = 1; i+n <= s.size(); ++i)
            {
                if (s[i+n-1]-s[i-1]>=target)
                {
                    return n;
                }
            }
        }
        return 0;
    }
};
