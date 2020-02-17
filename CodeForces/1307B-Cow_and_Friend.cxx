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
        ll n, d;
        cin >> n >> d;
        vector<ll> a(n);
        F(i, n)
            cin >> a[i];
        int i = 1;
        ll res = a[0];
        while (d > 0 && i < n)
        {
            ll c = d / i;
            ll real = min(a[i], c);
            d -= real * i;
            res += real;
            ++i;
        }
        cout << res << std::endl;
        
    }

    return 0;
}
 