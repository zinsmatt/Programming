#include <iostream>


int main()
{
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i)
    {
        long long n, k;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        
        long long l = 0;
        for (long long j = 0; j < n; ++j)
        {
            if (s[j] == '0')
            {
                long long nouv = std::max(l, j-k);
                k -= (j - nouv);
                std::swap(s[nouv], s[j]);
                ++l;
                if (k <= 0)
                    break;
            }
        }
        std::cout << s << "\n";
    }
    
    return 0;
}