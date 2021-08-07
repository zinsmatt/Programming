class Solution {
    
    
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        for (long long i = std::pow(2ull, n)-1; i >= 0; --i)
        {
            vector<int> s;
            auto x = i;
            int z = 0;
            while (x > 0)
            {
                if (x % 2)
                    s.push_back(z+1);
                x /= 2;
                ++z;
            }
            if (s.size() == k)
                res.push_back(std::move(s));
        }
        return res;
        
    }
};
