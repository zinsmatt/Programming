// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l = 1, r = n;
        while (l < r)
        {
            long m = (l+r) / 2;
            auto res = isBadVersion(m);
            if (res)
            {
                r = m;
            }
            else
            {
                l = m+1;
            }
        }
        return r;
    }
};
