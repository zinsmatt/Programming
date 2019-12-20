#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
 
int main()
{
    ll n;
    cin >> n;
    F(tt, n)
    {
        ll x;
        cin >> x;
        bool ok = false;
        for (ll i = 1; i <= 6; ++i)
        {
            if ((x - i) % 14 == 0)
            {
                ok = true;
                break;
            }
        }
        if (ok && x >= 15)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
   
    return 0;
}