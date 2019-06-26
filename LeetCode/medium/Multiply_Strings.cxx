class Solution {
public:
    string multiply(string num1, string num2) {
        std::vector<std::string> res;
        std::reverse(std::begin(num1), std::end(num1));
        std::reverse(std::begin(num2), std::end(num2));
        if (num1.size() < num2.size())
            std::swap(num1, num2);
        
        int max_len = 0;
        for (int i = 0; i < num2.size(); ++i)
        {
            std::stringstream ss;
            int f = num2[i] - '0';
            int reste = 0;
            for (int j = 0; j < i; ++j)
                ss << "0";
            for (auto const& c : num1)
            {
                int m = static_cast<int>(c - '0') * f;
                m += reste;
                ss << m % 10;
                reste = m / 10;
            }
            if (reste > 0)
                ss << reste;
            res.push_back(ss.str());
            if (ss.str().size()  > max_len)
            {
                max_len = ss.str().size();
            }
            //std::cout << res.back() << std::endl;
        }
        
        std::stringstream ss;
        int reste = 0;
        for (int i = 0; i < max_len; ++i)
        {
            int m = 0;
            for (int j = 0; j < res.size(); ++j)
            {
                if (i < res[j].size())
                {
                    m += static_cast<int>(res[j][i] - '0');
                }
            }
            
            m += reste;
            ss << m % 10;
            reste = m / 10;
            
        }
        if (reste > 0)
            ss << reste;
        std::string result = ss.str();
        std::reverse(std::begin(result), std::end(result));
        int i = 0;
        while (result[i] == '0')
            ++i;
        if (i >= result.size())
            return "0";
        else
            return result.substr(i);
    }
};