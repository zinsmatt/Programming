class Solution {
public:
    string convertToTitle(int n) {
        if (n == 1)
            return "A";
        int q = n;
        std::stringstream ss;
        while (q > 0)
        {
            int r = (q-1) % 26;
            ss << static_cast<char>('A' + r);
            q = (q - r ) / 26;
        }
        std::string res = ss.str();
        std::reverse(res.begin(), res.end());
        return res;
    }
};