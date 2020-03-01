// This is just a template solution used as initial script


#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>     /* abs */

 
#define F(i, n) for (ll i = 0; i < n; ++i)

#define VPRINT(name, v) \
    cout << name << " : "; \
    for (auto& e : v) { \
        cout << e << " "; \
    } \
    cout << std::endl; \

using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 


int main()
{
    ll tt;
    cin >> tt;
    F(t, tt)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        int ok = 0;
        ll maxi = 0;
        F(i, n){
            cin >> a[i];
            if (a[i] > maxi)
                maxi = a[i];
            if (a[i] == x)
            {
                ok = 1;
            }
            else if (a[i] > x && ok != 1)
            {
                ok = 2;
            }
        }

        if (ok == 0)
        {
            double res = (double)x / maxi;
            double res_ceil = std::ceil(res);
            if (std::abs(res - res_ceil) < 1e-6)
            {
                cout << (ll)res << std::endl;
            }
            else
            {
                cout << (ll)res + 1ll << std::endl;
            }
        }
        else
        {
            cout << ok << std::endl;
        }
        
    }

    return 0;
}
 