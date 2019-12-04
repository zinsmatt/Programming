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
        vector<int> occ(n+1, -1);
        int res = n+1;
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;

            if (occ[a] != -1)
            {
                res = min(res, i - occ[a] + 1);
            }
            occ[a] = i;
        }
        
        if (res == n+1)
            res = -1;
        cout << res << std::endl;
    }
    return 0;
}