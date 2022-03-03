class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        vector<int> v(32, 0);
        for (int i = 0; i < 32; ++i) {
            int c = 0;
            for (auto x : nums) {
                c += (x >> i) % 2;
            }
            
            c %= 3;
            if (c) {
                res += 1ll << i;
            }
        }
        return res;
        
    }
};
