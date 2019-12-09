#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;

using namespace std;

bool is_good(ll x)
{
    ll q = x;
    while (q > 0)
    {
        int r = q % 3;
        if (r == 2)
        {
            return false;
        }
        q = (q-r) / 3;        
    }
    return true;
}

vector<ll> good_numbers;

int main()
{
    for (int x = 1; x <= 1e4; ++x)
    {
        if (is_good(x))
        {
            good_numbers.push_back(x);
        }
    }
    int x = 1e4;
    while (is_good(x) == false)
        ++x;
    good_numbers.push_back(x);
    
    int t;
    cin >> t;
    
    F(i, t)
    {
        ll n;
        cin >> n;
        auto res = lower_bound(good_numbers.begin(), good_numbers.end(), n);
        cout << *res << std::endl;
    }
    return 0;
}