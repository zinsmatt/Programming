class Solution {
public:
    int singleNumber(vector<int>& nums) {

        vector<int> count(32, 0);
        int res = 0;

        for (int i = 0; i < 32; ++i)
        {
            int count = 0;
            for (auto x : nums)
            {
                count += (x >> i) % 2;
            }
            
            count %= 3;
            if (i == 31 && count)
            {
                res -= 1ll << i;
            } else if (count)
            {
                res += 1ll << i;
            }
        }
            
            
        return res;
        
    }
};
