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

ll solve(ll x)
{
    int last_2 = -1;
    int last_0 = -1;
    ll rest = 0;
    int i = 0;
    
    while (x > 0)
    {
        int r = x % 3;
    
        if (r == 0 && last_0 == -1)
        {
            rest = 0;
            last_0 = i;
        }
        if (r == 2)
        {
            last_0 = -1;
            last_2 = i;
        }
        
        if (i > last_0)
        {
            rest += r * std::pow(3, i);
        }
        x = (x - r) / 3;
        ++i;
        //cout << r << " ";
    }
    
    //cout << "\nlast 0 2 " << last_0 << " " << last_2 << std::endl;
    if (last_0 == -1)
        return std::pow(3, i);
    else
        return  std::pow(3, last_0) + rest;
}


int main()
{

    int t;
    cin >> t;
    
    F(i, t)
    {
        ll n;
        cin >> n;
        if (is_good(n))
            cout << n << std::endl;
        else
        {
            cout << solve(n) << std::endl;
        }
    }
    return 0;
}