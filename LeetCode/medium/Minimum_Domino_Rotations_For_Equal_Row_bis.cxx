class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        size_t n = tops.size();
        int min_nb = n+1;
        for (int t = 1; t <= 6; ++t) {
            int n_tops = 0;
            int n_bottoms = 0;
            for (size_t i = 0; i < n && (n_tops >= 0 || n_bottoms >= 0); ++i) {
                if (tops[i] != t) {
                    if (bottoms[i] == t)
                        ++n_tops;
                    else
                        n_tops = -1;
                }
                if (bottoms[i] != t) {
                    if (tops[i] == t)
                        ++n_bottoms;
                    else
                        n_bottoms = -1;
                }
            }
            if (n_tops >= 0)
                min_nb = min(min_nb, n_tops);
            if (n_bottoms >= 0)
                min_nb = min(min_nb, n_bottoms);
        }
        if (min_nb >= n)
            min_nb = -1;
        return min_nb;
    }

};
