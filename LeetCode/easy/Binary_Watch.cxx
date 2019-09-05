class Solution {
public:
    int bin(int x)
    {
        int q = x;
        vector<int> res;
        int n = 0;
        while (q > 0)
        {
            int r = q % 2;
            q = (q-r) / 2;
            n += r;
        }
        return n;
    }
    vector<string> readBinaryWatch(int num) {
        vector<int> hours;
        for (int i = 0; i < 12; ++i)
        {
            hours.push_back(bin(i));
        }
        
        vector<int> mins;
        for (int i = 0; i < 60; ++i)
        {
            mins.push_back(bin(i));
        }
        vector<string> res;
        
        for (int h = 0; h < 12; ++h)
        {
            for (int m = 0; m < 60; ++m)
            {
                if (hours[h] + mins[m] == num)
                {
                    stringstream ss;
                    ss << h << ":" << std::setfill ('0') << std::setw(2) << m;
                    res.push_back(ss.str());
                }
            }
        }
         return res;
    }
};