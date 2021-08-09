class Solution {
public:
    string addStrings(string num1, string num2) {
        int ret = 0;
        string res;
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        for (int i = 0; i < std::max(num1.size(), num2.size()); ++i)
        {
            int x = 0;
            if (i < num1.size())
                x += (int)(num1[i]-'0');
            if (i < num2.size())
                x += (int)(num2[i]-'0');
            x += ret;
            res += std::to_string(x % 10);
            ret = (x - x%10)/10;
        }
        if (ret > 0)
            res += "1";
        std::reverse(res.begin(), res.end());
        return res;
    }
};
