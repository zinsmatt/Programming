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
        ll n, d;
        cin >> n >> d;

        if (d <= n)
        {
            cout << "YES" << std::endl;
        }
        else
        {
            double delta = (1-(double)n)*(1-(double)n)-4*1*((double)d-(double)n);
            if (delta < 0)
            {
                cout << "NO" << std::endl;
            }
            else
            {
                double s1 = ((double)n-1-sqrt(delta))/2;
                double s2 = ((double)n-1+sqrt(delta))/2;
                double m = (s1+s2)/2;


                ll r1 = m;
                ll r2 = m+1;
                ll r3 = m-1;

                if (r1 + ceil(d/(r1+1)) <= n ||
                    r2 + ceil(d/(r2+1)) <= n ||
                    r3 + ceil(d/(r3+1)) <= n)
                {
                    cout << "YES" << std::endl;
                }
            }
        }
    }

    return 0;
}
