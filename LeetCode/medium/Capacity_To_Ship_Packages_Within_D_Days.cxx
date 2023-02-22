class Solution {
    int count(vector<int>& w, int s) {
        int c = s;
        int d = 1;
        for (auto x : w) {
            if (x > c) {
                ++d;
                c = s;
            }
            c -= x;
        }
        return d;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int s = 0;
        int max_w = 0;
        for (auto w : weights) {
            s += w;
            max_w = max(max_w, w);
        }

        // search from max_w to s;
        int l = max_w;
        int r = s;
        while (l < r) {
            int m = (l+r) / 2;
            m = (l+r) / 2;
            int dm = count(weights, m);
            if (days < dm) {
                // need larger
                l = m+1;
            } else {
                r = m;
            }
        }
        return l;        
    }
};
