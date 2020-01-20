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
    int n;
    cin >> n;
    double res = 0.0;
    for (int i = 1; i <= n; ++i)
    {
        res += 1.0 / i;
    }
    std::cout << res << "\n";
    return 0;
}