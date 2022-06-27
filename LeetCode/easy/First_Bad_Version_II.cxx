// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    long binary_search(long l, long r) {
        if (l == r)
            return l;
        
        long m = (l + r) / 2;
        auto s = isBadVersion(m);
        if (!s)
            return binary_search(m+1, r);
        else
            return binary_search(l, m);
    }

public:
    int firstBadVersion(int n) {
        return binary_search(1, n);        
    }
};
