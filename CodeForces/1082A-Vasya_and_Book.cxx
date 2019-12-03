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
        int n, x, y, d;
        cin >> n >> x >> y >> d;
        if (abs(y-x) % d == 0)
        {
            cout << abs(y-x) / d << "\n";
        }
        else
        {
            int res1 = -1;
            if ((y - 1) % d == 0)
            {
                int to_zero = static_cast<int>(ceil((float)(x - 1) / d));
                res1 = to_zero + (y - 1) / d;
                
            }
            
            int res2 = -1;
            if ((n - y) % d == 0)
            {
                int to_end = static_cast<int>(ceil((float)(n - x) / d));
                res2 = to_end + (n - y) / d;
            }
            if (res1 == -1 && res2 == -1)
                cout << -1 << "\n";
            else if (res1 == -1)
                cout << res2 << "\n";
            else if (res2 == -1)
                cout << res1 << "\n";
            else
                cout << min(res1, res2) << "\n";
        }
    }
    return 0;
}