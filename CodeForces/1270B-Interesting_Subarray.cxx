#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#define F(i, n) for (ll i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;

// To compute x^y under modulo m 
ll power(ll x,  ll y,  ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
  
// Function to return gcd of a and b 
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 
 
ll modInverse2(ll a, ll m) 
{ 
    ll g = gcd(a, m); 
    if (g != 1) 
        return 1;
     else
    { 
        return power(a, m-2, m); 
    } 
}


ll modInverse(ll a, ll m) 
{ 
    a = a%m; 
    for (ll x=1; x<m; x++) 
       if ((a*x) % m == 1) 
          return x; 
} 

int main()
{
    ll t;
    cin >> t;
    F(tt, t)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        bool ok = false;
        F(i, a)
        {
            int x;
            cin >> x;
            if (x == n)
                ok = true;
        }
        F(i, b)
        {
            int x;
            cin >> x;
        }
        if (ok)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    
    return 0;
}