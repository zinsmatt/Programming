class Solution {
public:
    int reverse(int x) {
        auto const& str = std::to_string(x);
        int s = 0;
        int mul = 1;
        if (str[0] == '-')
        {
            s = 1;
            mul = -1;
        }
        long long int res = 0;
        for (int i = str.size() - 1; i >= s; --i)
        {
            res += std::pow(10, i - s) * (str[i] - '0');
        }
        if (res != static_cast<int>(res))
            return 0;
        else
            return mul * res;
    }
};