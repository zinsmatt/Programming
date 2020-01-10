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
        int n;
        cin >> n;
        vector<ll> a(n);
        ll y = 0;
        F(i, n)
        {
            cin >> a[i];
            y += a[i];
            /*if (i > 0)
            {
                s[i] = s[i-1] + a[i];
            }
            else
                s[i] = a[i];*/
        }

        ll maxi = 0;
        ll cur = 0;
        int l = 0;
        for (int i = 0; i < n; ++i)
        {
            if (cur + a[i] > 0)
            {
                if (i - l + 1 < n)
                {
                    cur += a[i];
                    maxi = max(maxi, cur);
                }
            }
            else
            {
                l = i;
                cur = 0;
            }
        }



        if (maxi >= y)
            cout << "NO\n";
        else
        {
            reverse(a.begin(), a.end());
            ll maxi = 0;
            ll cur = 0;
            int l = 0;
            for (int i = 0; i < n; ++i)
            {
                if (cur + a[i] > 0)
                {
                    if (i - l + 1 < n)
                    {
                        cur += a[i];
                        maxi = max(maxi, cur);
                    }
                }
                else
                {
                    l = i;
                    cur = 0;
                }
            }
            if (maxi >= y)
                cout << "NO\n";
            else
                cout << "YES\n";
        }

    }
    

    return 0;
}