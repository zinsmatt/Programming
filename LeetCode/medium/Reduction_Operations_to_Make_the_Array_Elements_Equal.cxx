class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int end = nums.back();
        int i = 0;
        long long res = 0;
        while (i < nums.size()-1 && end != nums[i])
        {
            
            if (nums[i+1] != nums[i])
            {
                res += i+1;
            }
            ++i;
        }
        
        return res;
    }
};
