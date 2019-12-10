#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;

using namespace std;


int main()
{

    int t;
    cin >> t;
    
    F(i, t)
    {
        int n;
        cin >> n;
        vector<int> sizes(n, 0);
        int n0 = 0, n1 = 0;
        int last_idx = -1;
        F(j, n)
        {
            string s;
            cin >> s;
            sizes[j] = s.size();
            if (s.size() % 2 == 1)
                last_idx = j;
            for (auto& c : s)
            {
                if (c == '0')
                    ++n0;
                else
                    ++n1;
            }
        }
        
        if (last_idx == -1)
            last_idx = n-1;
            
        for (int j = 0; j < n; ++j)
        {
            if (j != last_idx)
            {
                int s = sizes[j];
                if (s % 2 == 0)
                {
                    int r = abs(min(n0 - s, 0));
                    n0 = max(0, n0 - s);
                    if (r % 2 == 1)
                    {
                        n0++;
                        r++;
                    }
                    n1 = n1 - r;
                }
                else
                {
                    int r = abs(min(n0 - s, 0));
                    n0 = max(0, n0 - s);
                    n1 = n1 - r;
                }
            }
        }
        
        if (sizes[last_idx] % 2 == 1)
        {
            cout << n << std::endl;
        }
        else
        {
            if (n0 % 2 == 1 || n1 % 2 == 1)
            {
                cout << n-1 << std::endl;
            }
            else
            {
                cout << n << std::endl;
            }
        }
    }
    return 0;
}