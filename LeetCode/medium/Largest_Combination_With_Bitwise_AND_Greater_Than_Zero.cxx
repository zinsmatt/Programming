class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res = 0;
        for (int i = 0; i < 32; ++i)  {
            int s = 1 << i;
            int r = 0;
            for (auto x : candidates) {
                r += (s & x) != 0;
            }
            res = max(res, r);
        }
        return res;
    }
};


