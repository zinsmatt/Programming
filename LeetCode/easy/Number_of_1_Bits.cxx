class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n > 0)
        {
            int r = n % 2;
            res += r;
            n = (n - r) / 2;
        }
        return res;
    }
};