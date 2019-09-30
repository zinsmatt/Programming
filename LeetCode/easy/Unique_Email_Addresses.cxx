class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, bool> map;
        for (auto const& s : emails)
        {
            auto pos = s.find('@');
            auto local = s.substr(0, pos);
            stringstream ss;
            for (auto c : local)
            {
                if (c == '+')
                    break;
                if (c != '.')
                    ss << c;
            }
            auto key = ss.str() + s.substr(pos);
            if (map.find(key) == map.end())
            {
                map[key] = true;
            }
        }
        
        return map.size();
    }
};