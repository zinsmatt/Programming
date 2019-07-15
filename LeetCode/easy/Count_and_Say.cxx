class Solution {
public:
    string countAndSay(int n) {
        std::string s = "1";
        int c = 1;
        while (c < n)
        {
            int i = 0;
            char const& p = s[0];
            std::stringstream ss;
            while (i < s.size())
            {
                auto const& p = s[i];
                ++i;
                int nb = 1;
                while (i < s.size() && s[i] == s[i-1])
                {
                    i++;
                    nb++;
                }
                ss << nb << p;                
            }
            s = ss.str();
            
            ++c;
        }
        return s;
    }
};