#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#define F(i, n) for (ll i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;



// Utility function to do modular exponentiation. 
// It returns (x^y) % p 
ll power(ll x,  ll y, ll p) 
{ 
    ll res = 1; // Initialize result 
    x = x % p; // Update x if it is more than or 
    // equal to p 
    while (y > 0) { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res * x) % p; 
  
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % p; 
    } 
    return res; 
} 
  
// Function to find modular inverse of a under modulo p 
// using Fermat's method. Assumption: p is prime 
ll modInverse(ll a, ll p) 
{ 
    return power(a, p - 2, p); 
} 
  
// Returns n! % p using Wilson's Theorem 
ll modFact(ll n, ll p) 
{ 
    // n! % p is 0 if n >= p 
    if (p <= n) 
        return 0; 
  
    // Initialize result as (p-1)! which is -1 or (p-1) 
    ll res = (p - 1); 
  
    // Multiply modulo inverse of all numbers from (n+1) 
    // to p 
    for (ll i = n + 1; i < p; i++) 
        res = (res * modInverse(i, p)) % p; 
    return res; 
} 

int main()
{
    int t;
    cin >> t;
    F(tt, t)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int maxi = 0;
        int cur = -1;
        int i = 0;
        while (i < n)
        {
            if (s[i] == 'A')
            {
                cur = 0;
            }
            else
            {
                if (cur >= 0)
                {
                    ++cur;
                    maxi = max(maxi, cur);
                }
            }
            ++i;
        }
        cout << maxi << "\n";
    }

    return 0;
}