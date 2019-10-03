class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int x = left; x <= right; ++x)
            if (check(x))
                res.push_back(x);
        return res;        
    }
    
    bool check(int x)
    {
        if (x >= 1 && x <= 9)
            return true;
        int q = x;
        while (q > 0)
        {
            int r = q % 10;
            q = (q - r) / 10;
            if (r == 0 || x % r != 0)
                return false;
        }
        return true;
    }
};
