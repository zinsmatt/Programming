class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) 
            return vector<string>();
        
        unordered_map<char, long long> encode;
        encode['A'] = 1;
        encode['C'] = 2;
        encode['G'] = 3;
        encode['T'] = 4;
        
        unordered_map<long long, int> m;
        long long code = 0;
        for (int i = 0; i < 10; ++i)
        {
            code += std::pow(10, i) * encode[s[i]];
        }
        m[code] = 1;
        
        vector<string> res;
        
        int i = 0;
        long long P = 1000000000ll;        
        while (i + 10 < s.size())
        {
            code -= encode[s[i]];
            code /= 10;
            i++;
            if (i + 9 >= s.size())
                break;
            code += P * encode[s[i+9]];
            
            if  (m.find(code) != m.end())
            {
                if (m[code] == 1)
                    res.push_back(s.substr(i, 10));
                m[code] = 2;
            } else {
                m[code] = 1;
            }
        }
        return res;
    }
};
