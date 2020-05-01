// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int l = 1, r = n;
        while (l < r)
        {
            long int m = (l+r)/2;
            auto res = isBadVersion(m);
            if (!res)
            {
                l = m+1;
            }
            else
            {
                r = m;
            }
        }
        return l;
        
    }
};
