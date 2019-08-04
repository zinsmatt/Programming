class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        int q = n;
        while (q > 0)
        {
            int r = q % 2;
            if (r == prev)
                return false;
            else
                prev = r;
            q = (q-r) / 2;
        }
        return true;
    }
};