class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() <= 3)
            return {};

        std::vector<string> res;
        for (int i = 1; i < std::min((int)s.size()-2, 4); ++i)
        {
            for (int j = i+1; j < std::min((int)s.size()-1, i+4); ++j)
            {
                for (int k = j+1; k < std::min((int)s.size(), j+4); ++k)
                {
                    if (s[0] == '0' && i > 1) continue;
                    if (s[i] == '0' && j > i+1) continue;
                    if (s[j] == '0' && k > j+1) continue;
                    if (s[k] == '0' && k < s.size()-1) continue;
                    if (s.size()-k > 3) continue;
                    int a = std::stoi(s.substr(0, i));
                    int b = std::stoi(s.substr(i, j-i));
                    int c = std::stoi(s.substr(j, k-j));
                    int d = std::stoi(s.substr(k));
                    if (a > 255 || b > 255 || c > 255 || d > 255)
                        continue;
                    res.push_back(std::to_string(a) + "." + std::to_string(b) + "." + std::to_string(c) + "." + std::to_string(d));
                }
            }
        }
        
        return res;
    }
};
