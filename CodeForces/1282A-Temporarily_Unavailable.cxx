#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 


int main()
{
    int t;
    cin >> t;
    F(tt, t)
    {
        ll a, b, c, r;
        cin >> a >> b >> c >> r;
        ll r1 = c-r, r2 = c+r;
        ll res = 0;
        if (a > b)
        {
            swap(a, b);
        }
        if (r == 0)
        {
            cout << b-a << "\n";
            continue;
        }
        if (a >= r1 && a <= r2)
        {
            if (b >= r1 && b <= r2)
            {
                res = 0;
                
            }else
            {
                res = b - r2;
            }
        }else
        {
            if (r1 > a)
            {
                if (r1 <= b)
                {
                    if (b <= r2)
                    {
                        res = r1 - a;
                    }
                    else
                    {
                        res = r1-a + b-r2;
                    }
                }
                else
                {
                    res = b-a;
                }
            }else
            {
                res = b-a;
            }
        }
        cout << res << "\n";
    }
    return 0;
}