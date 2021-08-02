class Solution {
public:
    int uniquePaths(int M, int N) {
        long long m = std::max(M, N) - 1;
        long long n = std::min(M, N) - 1;

        unsigned long long nm = 1;
        for (int i = m+1; i <= n+m; ++i) nm *= i;
        
        unsigned long long _n = 1;
        for (int i = 1; i <= n; ++i) _n *= i;
        
         
        return nm / _n;
    }
};
