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
        ll r, g, b;
        cin >> r >> g >> b;
        vector<ll> a = {r, g, b};
        sort(a.begin(), a.end());
        if (a[2] <= a[0]+a[1]+1)
        {
            cout << "Yes" << "\n";
        }
        else
        {
            cout << "No" << "\n";
        }

    }
    return 0;
}