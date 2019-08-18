class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long q = n;
        long res = 0;
        int c = 0;
        std::vector<int> temp(32, 0);
        while (q > 0)
        {
            int r = q % 2;
            temp[c++] = r;
            q = (q - r) / 2;
        }
        c = 0;
        for (auto it = temp.rbegin(); it != temp.rend(); ++it)
        {
            res += *it * std::pow(2, c++);
        }
        return res;
    }
};