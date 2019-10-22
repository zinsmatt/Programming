class Solution {
public:
    int findComplement(int num) {
        int q = num;
        int res = 0;
        int p = 0;
        while (q > 0)
        {
            int r = q % 2;
            res += std::pow(2, p++) * (1-r);
            q = (q - r) / 2;
        }
        return res;
    }
};