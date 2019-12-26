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
        ll n, p, k;
        cin >> n >> p >> k;
        vector<ll> a(n);
        ll imp = 0, pair = 0;
        F(i, n)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int i = 0;
        ll s = 0;
        while (i < a.size())
        {
            if (s + a[i] <= p)
            {
                s += a[i];
                pair++;
                i += 2;
                //cout << "s = " << s <<  "\n";
                //cout << "i = " << i <<  "\n";

            }
            else
                break;
        }
        int pair_i = max(0, i-1);
        ll pair_s = s;
        i = 1;
        s = 0;
        while (i < a.size())
        {
            if (s + a[i] <= p)
            {
                s += a[i];
                imp++;
                i += 2;
            }
            else
                break;
        }
        ll imp_s = s;
        int imp_i = max(0, i-1);
        cout << max(imp_i, pair_i) << "\n";


    }
    return 0;
}