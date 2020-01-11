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
    int n;
    cin >> n;
    vector<int> occ(n+1, 0);
    vector<int> a(n, 0);
    int cost = 0;
    F(i, n)
    {
        int x;
        cin >> x;
        occ[x]++;
        if (x == 0)
        {
            a[i] = 0;
        }
        else if (x%2 == 1)
        {
            a[i] = 1;
        }
        else
        {
            a[i] = 2;
        }
        if (i > 0)
        {
            if (a[i] != 0 && a[i-1] != 0 && a[i] %2 != a[i-1] % 2)
                cost++;
        }
    }
    int np = 0, ni = 0;
    for( int i = 1; i <= n; ++i)
    {
        if (occ[i] == 0)
        {
            if (i% 2 == 1)
                ni++;
            else
                np++;
        }
    }

    vector<int> ti, tp;
    int left, right;
    int i = 0;
    while (i < n && a[i] == 0)
        ++i;
    left = i;
    i = n-1;
    while (i >= 0 && a[i] == 0)
        --i;
    right = i;

    if (left > right)
    {
        // only 0
        if (n > 1)
            cout << 1 << "\n";
        else
        {
            cout << "0\n";
        }

    }
    else
    {
        vector<int> exti, extp;
        if (left > 0)
        {
            if (a[left] % 2 == 1)
                exti.push_back(left);
            else
                extp.push_back(left);
        }
        if (right < n-1)
        {
            if (a[right] % 2 == 1)
                exti.push_back(n-1-right);
            else
                extp.push_back(n-1-right);
        }

        int i = left+1;
        while (i < right)
        {
            if (a[i] == 0)
            {
                int l = a[i-1];
                int prev_i = i;
                while (a[i] == 0)
                    ++i;
                int r = a[i];
                int len = i-prev_i;
                if (l%2 == r%2)
                {
                    if (l%2 == 1)
                        ti.push_back(len);
                    else
                        tp.push_back(len);
                }
                else
                {
                    cost++;
                }
            }
            ++i;
        }


        /*for (auto x : ti )
            cout << x << " " ;
        cout << std::endl;
        for (auto x : tp )
            cout << x << " " ;
        cout << std::endl;
        for (auto x : exti )
            cout << x << " " ;
        cout << std::endl;
        for (auto x : extp )
            cout << x << " " ;
        cout << std::endl;*/

        sort(ti.begin(), ti.end());
        sort(tp.begin(), tp.end());

        sort(exti.begin(), exti.end());
        sort(extp.begin(), extp.end());

        for (auto c : ti)
        {
            if (ni >= c)
            {
                ni-=c;
            }
            else
            {
                cost += 2;
            }
        }
        for (auto c : tp)
        {
            if (np >= c)
            {
                np-=c;
            }
            else
            {
                cost += 2;
            }
        }

        for (auto c : exti)
        {
            if (ni >= c)
            {
                ni-=c;
            }
            else
            {
                cost += 1;
            }
        }
        for (auto c : extp)
        {
            if (np >= c)
            {
                np-=c;
            }
            else
            {
                cost += 1;
            }
        }

        cout << cost << std::endl;
    }



    return 0;
}