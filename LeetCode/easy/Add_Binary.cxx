class Solution {
public:
    string addBinary(string a, string b) {
        int r = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        std::stringstream ss;
        for (int k = 0; k < std::max(a.size(), b.size()); ++k)
        {
            int aa = 0, bb = 0;
            if (i >= 0)
                aa = static_cast<int>(a[i] - '0');
            if (j >= 0)
                bb = static_cast<int>(b[j] - '0');
            ss << (aa + bb + r) % 2;
            if (aa + bb + r > 1)
                r = 1;
            else
                r = 0;
            --i;
            --j;
        }
        if (r > 0)
            ss << 1;
        auto res = ss.str();
        std::reverse(res.begin(), res.end());
        return res;
    }
};