class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = -1;
        for (int k = 1; k <= 6; ++k) {
            int nb_top = 0, nb_bot = 0;
            int count = 0;
            for (int i = 0; i < tops.size(); ++i) {
                bool ok = false;
                if (tops[i] == k) {
                    nb_top++;
                    ok = true;
                }
                if (bottoms[i] == k) {
                    nb_bot++;
                    ok = true;
                }
                count += ok;
            }
            if (count == tops.size()) {
                if (res == -1 || tops.size()-std::max(nb_top, nb_bot) < res) {
                    res = tops.size()-std::max(nb_top, nb_bot);
                }
            }
        }
        return res;
    }
};
