class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Normal sum
        long maxv = numeric_limits<long>::min();
        int n = nums.size();
        long cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += nums[i];
            maxv = max(maxv, cur);
            cur = max(cur, 0l);
        }
               
        // Prefix-Suffix
        vector<long> cum_sum(n, 0);
        cum_sum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            cum_sum[i] = cum_sum[i-1] + nums[i];
        }
        // cout << "computed cum sum" << endl;
        vector<long> cum_sum_inv(n, 0);
        cum_sum_inv[n-1] = nums[n-1];
        vector<long> max_right(n, 0);
        max_right[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; --i) {
            cum_sum_inv[i] = cum_sum_inv[i+1] + nums[i];
            max_right[i] = max(max_right[i+1], cum_sum_inv[i]);
        }
        // cout << "computed cum sum inv" << endl;

        for (int i = 0; i < n-1; ++i) {
            maxv = max(maxv, cum_sum[i] + max_right[i+1]);
        }        
        return maxv;

    }
};
