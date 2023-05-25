class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> res(nums.size(), 0);
        long long prev = 0;
        int m = 0;
        for (int i = 0; i < nums.size(); ++i) {
            m = max(m, nums[i]);
            res[i] = prev  + (long long)(nums[i] + m);
            prev = res[i];
        }
        return res;
    }
};
