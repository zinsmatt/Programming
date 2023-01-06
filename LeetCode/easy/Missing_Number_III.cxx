class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int s = 0;
        for (int i = 0; i <= nums.size(); ++i) {
            s ^= i;
        }
        for (auto x : nums)
            s ^= x;
        return s;
    }
};
