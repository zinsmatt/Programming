class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> out(nums.size(), -1);
        if (nums.size() < 2*k+1)
            return out;

        unsigned long long sum = accumulate(nums.begin(), nums.begin()+2*k+1, 0ull);
        int a = 0;
        int b = 2*k+1;

        long long N = 2*k+1;
        while (b <= nums.size()) {
            // cout << "i = " << a + k << "\n";
            // cout << "sum = " << sum << "\n";
            out[a+k] = sum / N;
            sum -= nums[a];
            if (b < nums.size())
                sum += nums[b];
            ++a;
            ++b;
        }

        return out;
        
    }
};
