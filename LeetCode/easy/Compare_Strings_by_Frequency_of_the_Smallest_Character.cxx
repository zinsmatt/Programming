class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto fq = f(queries);
        auto fw = f(words);
        vector<int> res(fq.size(), 0);
        for (int qi = 0; qi < fq.size(); ++qi)
        {
            int c = 0;
            for (auto& w : fw)
                if (w > fq[qi])
                    ++c;
            res[qi] = c;
        }
        return res;
    }
    
    std::vector<int> f(vector<string>& s)
    {
        vector<int> res(s.size(), 0);
        for (int i = 0; i < s.size(); ++i)
        {
            char c = 'z' + 1;
            int count = 0;
            for (auto cc : s[i])
            {
                if (cc < c)
                {
                    c = cc;
                    count = 1;
                }
                if (cc == c)
                    ++count;
            }
            res[i] = count;
        }
        return res;
    }
};