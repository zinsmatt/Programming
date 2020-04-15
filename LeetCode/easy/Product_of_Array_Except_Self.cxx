class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> pref(n + 1, 1), suff(n + 1, 1);
        for (int i = 1; i < nums.size(); ++i)
        {
            pref[i] = pref[i-1] * nums[i-1];
            suff[n-i] = suff[n-i+1] * nums[n-1-(i-1)];
        }
        
        vector<int> res(n);
        for (int i = 1; i <= n; ++i)
        {
            res[i-1] = pref[i-1] * suff[i];
        }
        return res;
    }
};
