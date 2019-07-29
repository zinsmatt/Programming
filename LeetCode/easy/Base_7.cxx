class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        std::stringstream ss;
        int q = num;
        if (num < 0)
        {
            q = -q;
        }
        while (q > 0)
        {
            int r = q % 7;
            q = (q-r) / 7;
            ss << r;
        }
        if (num < 0)
            ss << "-";
        
        auto res = ss.str();
        std::reverse(res.begin(), res.end());
        return res;
    }
};