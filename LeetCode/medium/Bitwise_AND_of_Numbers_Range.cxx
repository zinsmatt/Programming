class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (n == m) return n;
        else
        {
            int d = n-m;
            int i = 0;
            while (d > 0)
            {
                n = n & ~(1 << i);
                m = m & ~(1 << i);
                d >>= 1;
                ++i;
            }
            return m & n;
        }
        
    }
};
