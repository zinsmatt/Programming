#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 


int main()
{
    ll n, d, e;
    cin >> n >> d >> e;
    ll res = n;

    ll y = 0;
    while (y*e <= n)
    {
        res = min(res, (n-(y*e)) % d);
        y += 5;
    }

    cout << res << "\n";

    return 0;
}
