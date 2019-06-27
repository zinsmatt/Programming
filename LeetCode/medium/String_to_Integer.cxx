class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0)
            return 0;
        int i = 0;
        while (str[i] == ' ')
            ++i;
        int f = 1;
        if (str[i] == '-')
        {
            f = -1;
            ++i;
        }
        else if (str[i] == '+')
        {
            f = 1;
            ++i;
        }
        int start = i;
        while (i < str.size() && str[i] <= '9' && str[i] >= '0')
            ++i;
        if (start == i)
            return 0;
        long res = std::atol(str.substr(start, i - start).c_str());
        res *=  f;
        if (res < INT_MIN)
            return INT_MIN;
        else if (res > INT_MAX)
            return INT_MAX;
        else
            return res;
        
    }
};