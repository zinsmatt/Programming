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
        ll n, k;
        cin >> n >> k;
        ll r = n % k;
        r = max(0ll, r - (k / 2));
        cout << n - r << std::endl;
    }
   
    return 0;
}
