class Solution {

    long long eval(vector<int>& arr, int x) {
        long long r = 0;
        for (auto a : arr)
            r += std::ceil(static_cast<double>(a) / x);
        return r;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *std::max_element(piles.begin(), piles.end());

        int l = 1;
        int r = max;

        while (l < r) {
            long long m = ((long long)l + (long long)r) / 2;
            long long n = eval(piles, m);

            if (n <= h) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }
};
