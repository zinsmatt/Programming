#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;

using namespace std;


int main()
{
    int t;
    cin >> t;
    F(tt, t)
    {
        int n;
        cin >> n;
        vector<int> p(1+n);
        for (int j = 1; j <= n; ++j)
        {
            cin >> p[j];
        }
        vector<int> pt(1+n, -1);
        vector<int> res(n, 0);
        int cur = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (pt[j] == -1)
            {
                int c = 0;
                int idx = j;
                while (c == 0 || idx != j)
                {
                    pt[idx] = cur;
                    ++c;
                    idx = p[idx];
                }
                res[cur++] = c;
                cout << c << " ";
            }
            else
            {
                cout << res[pt[j]] << " ";
            }
        }
        cout << std::endl;
        
    }
   
 
   
    return 0;
}