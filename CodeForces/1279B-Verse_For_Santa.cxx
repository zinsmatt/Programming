#include <iostream>
#include <bits/stdc++.h>
#include <queue>
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
        ll n, s;
        cin >> n >> s;
        vector<ll> a(n);
        F(i, n)
        {
            cin >> a[i];
        }
        int i = 0;
        ll cur = s;
        ll maxi = a[0];
        ll i_max = 0;
        while (i < n && cur > 0)
        {
            if (a[i] > maxi)
            {
                maxi = a[i];
                i_max = i;
            }
            if (a[i] <= cur)
            {
                cur -= a[i];
                ++i;
            }
            else
            {
                break;
            }
        }

        if (i == n)
        {
            cout << "0\n";
        }
        else
        {
            if (maxi + cur < a[i])
                cout << "0\n";
            else
                cout << i_max+1 << "\n";
        }

    }
    return 0;
}