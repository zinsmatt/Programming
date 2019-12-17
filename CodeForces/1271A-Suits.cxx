#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
 
int main()
{
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
 
    ll res;
    if (e > f)
    {
        res = min(a, d) * e + min(max(0ll, d-a), min(b, c))*f;
    }
    else
    {
        res = min(min(b, c), d) * f + min(max(0ll, d-min(b, c)), a) * e;
    }
    
    cout << res;
    
    
    return 0;
}