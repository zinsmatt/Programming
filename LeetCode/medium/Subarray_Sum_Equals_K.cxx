class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> cum(nums.size()+1, 0);
        for (int i = 1; i < nums.size()+1; ++i)
        {
            cum[i] = cum[i-1] + nums[i-1];
        }
        
        int res = 0;
        unordered_map<int, int> m;
        m[k] = 1;
        for (int i = 1; i < nums.size()+1; ++i)
        {
            if (m.find(cum[i]) != m.end())
            {
                res += m[cum[i]];
            }
            
            if (m.find(cum[i]+k) == m.end())
            {
                m[cum[i]+k] = 1;
            }else
            {
                m[cum[i]+k]++;
            }
        }
        return res;
    }
};
