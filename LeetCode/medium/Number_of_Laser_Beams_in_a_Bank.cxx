class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int c = 0;
        int res = 0;
        for (int i = 0; i < bank.size(); ++i) {
            int r = 0;
            for (auto x : bank[i]) {
                if (x == '1')
                    r++;
            }
            if (r != 0) {
                res += c * r;
                c = r;
            }
        }
        return res;
    }
};
