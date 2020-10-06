class Solution {
public:
    int str_to_int(const string& s)
    {
        int r = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            r += pow(2, i) * static_cast<int>(s[i] == '1');
        }
        return r;        
    }
    
    
    vector<int> grayCode(int n) {
        if (n == 0) return {0};
        vector<string> l = {"0", "1"};
        for (int i = 0; i < n-1; ++i)
        {
            for (int j = l.size()-1; j >= 0; --j)
                l.push_back(l[j]);
            for (int j = 0; j < l.size()/2; ++j)
                l[j] = "0" + l[j];
            for (int j = l.size()/2; j < l.size(); ++j)
                l[j] = "1" + l[j];
        }
        vector<int> res(l.size());
        for (int i = 0; i < l.size(); ++i)
        {
            res[i] = str_to_int(l[i]);
        }
        return res;
    }
};
