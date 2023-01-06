class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;

        int res = 0;
        while (n) {
            int r = n % 3;
            n -= r;
            n /= 3;
            if (r == 2 || r == 1 && n > 0)
                return false;
        }
        return true;
    }
};
