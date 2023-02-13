class Solution {
public:
    int countOdds(int low, int high) {
        int n = (high-low+1) / 2;
        if (low % 2 == 1 && high % 2 == 1)
            ++n;
        return n;
    }
};
