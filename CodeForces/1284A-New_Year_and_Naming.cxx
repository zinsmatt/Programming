#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#define F(i, n) for (ll i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;




int main()
{
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<string> t(m);
    F(i, n)
    {
        cin >> s[i];
    }
    F(i, m)
    {
        cin >> t[i];
    }

    int q;
    cin >> q;
    F(i, q)
    {
        int x;
        cin >> x;
        --x;
        cout << s[x%n] << t[x%m] << "\n";
    }
   
    return 0;
}