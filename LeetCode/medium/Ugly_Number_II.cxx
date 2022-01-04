class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long int> v(50000, 0);
        int a=0;
        for (int i = 0; i < 32; ++i)
        {
            for (int j = 0; j < 20; ++j)
            {
                for (int k = 0; k < 14; ++k)
                {
                    long long int b = pow(2ll, i);
                    long long int c = pow(3ll, j);
                    long long int d = pow(5ll, k);
                    
                    if (i+j+k > 32) continue;
                    
                    long long int x = b * c * d;
                    if (x < std::numeric_limits<int>::max())
                    {
                        v[a++] = x;
                    }
                }
            }
        }
        sort(v.begin(), v.begin()+a);
        return v[n-1];
        
    }
};
