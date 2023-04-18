class Solution {

    tuple<int, int, int> count(const string& s) {
        int m = 0, p = 0, g = 0;
        for (auto& c : s) {
            if (c == 'M')
                ++m;
            else if (c == 'P')
                ++p;
            else
                ++g;
        }
        return std::make_tuple(m, p, g);
    }
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int m = 0, p = 0, g = 0;
        long long res = 0;
        for (int i = 0; i < garbage.size(); ++i) {
            auto [nm, np, ng] = count(garbage[i]);
            if (nm > 0) {
                while (m < i) {
                    res += travel[m];
                    ++m;
                }
            }
            if (np > 0) {
                while (p < i) {
                    res += travel[p];
                    ++p;
                }
            }
            if (ng > 0) {
                while (g < i) {
                    res += travel[g];
                    ++g;
                }
            }
            res += nm + np + ng;
        }
        return res;        
    }
};
