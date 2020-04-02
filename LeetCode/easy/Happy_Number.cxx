class Solution {
public:
    bool isHappy(int n) {
        std::unordered_map<long long, int> m;
        long long x = n;
        while (x != 1)
        {
            long long r = 0;
            int i = 0;
            while (x > 0)
            {
                r += std::pow(x % 10, 2);
                x = (x - x%10) / 10;
                ++i;
            }
            x = r;
            if (m.find(x) != m.end())
            {
                return false;
            }
            else
            {
                m[x] = 1;
            }
        }
        return true;
    }
};
