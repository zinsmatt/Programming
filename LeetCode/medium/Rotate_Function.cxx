class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long S = std::accumulate(nums.begin(), nums.end(), 0);
        long i = nums.size()-1;
        long cur = 0;
        for (long j = 0; j < nums.size(); ++j)
        {
            cur += j * nums[j];
        }
        long res = cur;
        //std::cout << " S = " << S << "\n";
        while (i >= 0)
        {
            //std::cout << cur << "\n";
            res = std::max(res, cur);
            cur += S;
            cur -= nums[i] * nums.size();
            --i;
        }
        return res;
    }
};
