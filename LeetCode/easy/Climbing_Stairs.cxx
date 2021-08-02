class Solution {
public:
    
    // too slow (duplicated computation like in recursive fibo)
    int solve(int x)
    {
        if (x <= 0) return 1;
        if (x == 1) return solve(x-1);
        return solve(x-1) + solve(x-2);
    }
    
    
    int climbStairs(int n) {
        vector<long long> v(n+1, 0);
        v[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            v[i+1] += v[i];
            if (i < n-1)
                v[i+2] += v[i];
        }
        
        return v.back();
    }
}
