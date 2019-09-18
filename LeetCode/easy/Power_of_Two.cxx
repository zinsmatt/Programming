class Solution {
public:
    bool isPowerOfTwo(int n) {
        double r = std::log2(n);
        std::cout << r;
        return r - std::floor(r) < 1e-12; 
    }
};