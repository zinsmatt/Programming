class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (const auto& s : queries)
            res.push_back(match(s, pattern));
        return res;
    }
    
    bool match(const std::string& q, const std::string& p)
    {
        // std::cout << q << " " << p << "\n";
        if (q.size() < p.size())
            return false;
        int up = 0;
        int a = 0;
        int res = 0;
        for (auto c : p)
        {
            while (a < q.size() && q[a] != c)
            {
                ++a;
            }
            if (a >= q.size())
                break;
            if (q[a] == c)
            {
                ++res;
                ++a;
            }
        }
        
        for (auto c : q)
        {
            if (tolower(c) != c)
                ++up;
        }
        // std::cout << "up " << up << "\n";
        for (auto c : p)
        {
            if (tolower(c) != c)
                --up;
        }
        // std::cout << "up " << up << "\n";
        return res == p.size() && up == 0;
    }
};