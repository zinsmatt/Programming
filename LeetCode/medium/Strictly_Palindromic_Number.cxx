class Solution {
    
    bool is_pal(int n, int b) {
        vector<int> res;
        while (n) {
            auto r = n % b;
            res.push_back(r);
            n /= b;           
        }
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] != res[res.size()-1-i])
                return false;
        }
        return true;
    }

    
public:
    bool isStrictlyPalindromic(int n) {
        for (int b = 2; b <= n-2; ++b) {
            if (!is_pal(n, b))
                return false;
        }
        return true;
    }
};
