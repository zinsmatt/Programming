class Solution {
public:
    int minOperations(int n) {
        if (n%2)
        {
            auto k = (n-1);
            return (k/2+1) * (k/2);
        }
        else
        {
            return n/2 * (1 + 1+2*(n/2-1)) / 2;
        }
    }
};
