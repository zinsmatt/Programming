class Solution {
    
public:
    int triangularSum(vector<int>& nums) {
        for (int n = nums.size(); n >= 1; --n) {
            vector<int> out(n-1, 0);
            for (int i = 0; i < n-1; ++i) {
                out[i] = (nums[i] + nums[i+1]) % 10;   
            }
            nums = out;
        }
        return nums.front() % 10;
    }
};
