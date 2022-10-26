class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int s = 0;
        int i = 0;
        for (int i = 0; i < 32; ++i) {
            int r1 = abs(a % 2);
            int r2 = abs(b % 2);
            
            int x = r1 ^ r2 ^ s;
            if (r1 && r2 || r1 && s || r2 && s)
            {
                s = 1;
            } else
            {
                s = 0;
            }
            // std::cout << "i = " << i << " = " << r1 << " " << r2 << " " << s << "\n";
            
            res |= x<<i;
            
            // std::cout << "\n" << std::bitset<32>(a) << "\n";
            // std::cout << std::bitset<32>(b) << "\n";
            a >>= 1;
            b >>= 1;
            // std::cout << std::bitset<32>(res) <<"\n\n";
        }
    
        return res;
    }
};
