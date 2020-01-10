#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
ll pgcd (ll a, ll b) {
  ll r;
  
  while (b > 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

ll ppcm(ll a, ll b)
{
    if (a == 0 || b == 0)
        return 0;
    else
        return (a*b)/pgcd(a, b);
}

int main()
{
    ll x;
    cin >> x;
    if (x == 1){
        cout << "1 1\n";
        return 0;
    }

    vector<ll> div;
    for (ll i = 1; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            div.push_back(i);
            div.push_back(x/i);
        }
    }    
    sort(div.begin(), div.end());
    ll mini = x;
    ll aa = 1;
    ll bb = x;
    for (int i = 1; i < div.size(); ++i)
    {
        bool end = false;
        for (int j = 0; j < i; ++j)
        {
            if (ppcm(div[i], div[j]) == x)
            {
                aa = div[i];
                bb = div[j];
                end  = true;
                break;
                /*ll m = max(div[i], div[j]);
                if (m < mini)
                {
                    mini = m;
                    aa = div[i];
                    bb = div[j];
                }*/
            }
        }
        if (end)
            break;
    }
    cout << aa << " " << bb << std::endl;
    return 0;
}