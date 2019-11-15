class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        ++k;
        for (int i = 0; i < k && i < nums.size(); ++i)
        {
            if (m.find(nums[i]) == m.end())
                m[nums[i]] = 1;
            else
                return true;           
        }
        
        for (int i = k; i < nums.size(); ++i)
        {
            m[nums[i-k]] = 0;
            if (m.find(nums[i]) != m.end() && m[nums[i]] == 1)
                return true;
            else
                m[nums[i]] = 1;
        }
        return false;
    }
};