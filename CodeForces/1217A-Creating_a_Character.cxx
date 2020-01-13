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
    F(i, n)
    {
        ll str, it, fr;
        cin >> str >> it >> fr;
        ll res;

        if (fr == 0)
        {
            if (str > it)
                res = 1;
            else res = 0;
        }
        else if (str == it)
        {
            res = fr - ((fr / 2) + 1) + 1;
        }
        else if (str > it)
        {

            ll D = str - it;
            auto lim = max(0ll, 1 + (ll)floor((double)(fr - D) / 2));
            res = fr - lim + 1;
        }
        else
        {
            ll D = it - str;
            auto lim = (fr + D) / 2 + 1;
            res = fr - lim + 1;
        }
        cout << max(0ll, res) << std::endl;

    }
    return 0;
}
