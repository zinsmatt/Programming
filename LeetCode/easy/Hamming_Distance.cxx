class Solution {
public:
    int hammingDistance(int x, int y) {
        vector<int> a(32, 0), b(32, 0);
        int i = 0, j = 0;
        while (x > 0)
        {
            int r = x % 2;
            x = (x - r) / 2;
            a[i++] = r;
        }
        
        while (y > 0)
        {
            int r = y % 2;
            y = (y - r) / 2;
            b[j++] = r;
        }
        
        int res = 0;
        for (int i = 0; i < a.size(); ++i)
            res += static_cast<int>(a[i] != b[i]);
        return res;        
    }
};