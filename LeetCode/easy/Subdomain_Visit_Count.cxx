class Solution {
public:
    vector<string> extract_domains(const string& s)
    {
        vector<string> res;
        if (s.size() > 0)
        {
            res.push_back(s);
            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] == '.' && i < s.size()-1)
                {
                    res.push_back(s.substr(i+1));
                }
            }
        }
        return res;
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> map;
        
        for (auto& s : cpdomains)
        {
            stringstream ss;
            ss.str(s);
            int n;
            string domain;
            ss >> n >> domain;
            auto sub = extract_domains(domain);
            for (auto& d : sub)
            {
                if (map.find(d) != map.end())
                {
                    map[d] += n;
                }
                else
                {
                    map[d] = n;
                }
            }
        }
        
        vector<string> res;
        for (auto it : map)
        {
            stringstream ss;
            ss << it.second << " " << it.first;
            res.push_back(ss.str());
            ss.str("");
            ss.clear();
        }
        return res;        
    }
};