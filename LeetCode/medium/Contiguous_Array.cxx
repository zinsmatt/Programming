class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> cum(n+1, 0);
        for (int i = 0; i < n ; ++i)
        {
            cum[1+i] = cum[i] + nums[i];
        }
        for (auto & v : cum)
            v *= 2;
        
        vector<int> diff(n+1, 0);
        for (int i = 0; i < n+1; ++i)
        {
            diff[i] = cum[i] - i;
        }
        
        vector<int> ind(n+1);
        iota(ind.begin(), ind.end(), 0);
        
        sort(ind.begin(), ind.end(), [&diff](int a, int b)
             {
                 if (diff[a] == diff[b])
                     return a < b;
                 else
                     return diff[a] < diff[b];
             });
        
        
        int prev = 0;
        int cur = 0;
        int res = 0;
        while (prev < n+1)
        {
            cur = prev + 1;
            while (cur < n+1 && diff[ind[cur]] == diff[ind[prev]])
            {
                res = max(res, ind[cur] - ind[prev]);
                ++cur;
            }
            prev = cur;
        }
        
        return res;
    }
};
