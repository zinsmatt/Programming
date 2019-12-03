#include <iostream>
#include <bits/stdc++.h>

using ll =  long long;

using namespace std;


ll smallestPrimeDiv(ll x)
{
    for (ll i = 2; i*i <= x; ++i)
    {
        if (x % i == 0)
            return i;
    }
    return x;
}


int main()
{
    ll t;
    cin >> t;
    ll d = smallestPrimeDiv(t);
    
    ll res = 1 + (t - d) / 2;
    cout << res << std::endl;
    
    return 0;
}