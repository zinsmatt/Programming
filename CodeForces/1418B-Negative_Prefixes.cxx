// This is just a template solution used as initial script


#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>     /* abs */

 
#define F(i, n) for (ll i = 0; i < n; ++i)

#define VPRINT(name, v) \
    cout << name << " : "; \
    for (auto& e : v) { \
        cout << e << " "; \
    } \
    cout << std::endl; \
    cout.flush(); \

#define LPRINT(name, l) \
    cout << "list " << name << " : "; \
    for (auto it = l.begin(); it != l.end(); ++it) { \
    	cout << *it << " "; \
    } \
    cout << std::endl; \

using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
#define INF std::numeric_limits<int>::max()
#define LLINF std::numeric_limits<long long>::max()


template <typename T, typename A>
int arg_max(std::vector<T, A> const& vec) {
  return static_cast<int>(std::distance(vec.begin(), max_element(vec.begin(), vec.end())));
}

template <typename T, typename A>
int arg_min(std::vector<T, A> const& vec) {
  return static_cast<int>(std::distance(vec.begin(), min_element(vec.begin(), vec.end())));
}

int dfs(const vector<vector<int>>& g, vector<int>& dist, int start, int end=-1)
{
	// g is a list of neighbours for each node
    // dist is assumed to be filled with INF
    queue<int> q;
    q.push(start);
    queue<int> d;
    d.push(0);
    while (q.size() > 0)
    {
        auto x = q.front();
        auto dd = d.front();
        q.pop();
        d.pop();

        if (dist[x] == INF)
        {
            dist[x] = dd;
            if (end == x)
                break;

            for (auto e: g[x]) {
                q.push(e);
                d.push(dd+1);
            }
        }
    }
    if (end >= 0 && end < dist.size())
        return dist[end];
    else
        return -1;
}

// Returns largest power of p that divides n! 
ll largestPower(ll n, ll p) 
{ 
    // Initialize result 
    ll x = 0; 
  
    // Calculate x = n/p + n/(p^2) + n/(p^3) + .... 
    while (n) { 
        n /= p; 
        x += n; 
    } 
    return x; 
} 
  
// Utility function to do modular exponentiation. 
// It returns (x^y) % p 
ll power(ll x, ll y, ll p) 
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
  
// Returns n! % p 
ll modFact(ll n, ll p) 
{ 
    if (n >= p) 
        return 0; 
  
    ll res = 1; 
  
    // Use Sieve of Eratosthenes to find all primes 
    // smaller than n 
    bool isPrime[n + 1]; 
    memset(isPrime, 1, sizeof(isPrime)); 
    for (ll i = 2; i * i <= n; i++) { 
        if (isPrime[i]) { 
            for (ll j = 2 * i; j <= n; j += i) 
                isPrime[j] = 0; 
        } 
    } 
  
    // Consider all primes found by Sieve 
    for (ll i = 2; i <= n; i++) { 
        if (isPrime[i]) { 
            // Find the largest power of prime 'i' that divides n 
            ll k = largestPower(n, i); 
  
            // Multiply result with (i^k) % p 
            res = (res * power(i, k, p)) % p; 
        } 
    } 
    return res; 
} 



#define MOD 998244353

int G = 0;
int ask(int i, int j)
{
	cout << "? " << 1+i << " " << j+1 << "\n";
	cout.flush();
	int r;
	cin >> r;
	G++;
	return r;
}

ull custom_pow(ull x, ull y)
{
    ull r = 1;
    F (i, y)
        r *= x;
    return r;
}

ull custom_stoul(const string& s)
{
    ull res = 0ull;
    for (auto c : s)
    {
        res = 10ull * res + static_cast<ull>(c-'0');
    }
    return res;
}

int main()
{
	ll tt = 1;
	cin >> tt;

	F(t, tt)
	{
        ll n;
        cin >> n;
        vector<ll> a(n);
        F (i, n) cin >> a[i];
        vector<int> locked(n);
        F (i, n) cin >> locked[i];


        auto s = accumulate(a.begin(), a.end(), 0);

        vector<ll> b;
        F (i, n)
        {
            if (locked[i] == 0)
                b.push_back(a[i]);
        }
        sort(b.begin(), b.end(), greater<ll>());
        int i = 0, j = 0;
        vector<ll> res(n);
        while (i < n)
        {
            if (locked[i] == 0)
            {
                res[i] = b[j++];
            }
            else
            {
                res[i] = a[i];
            }
            ++i;
        }

        for (auto c : res)
            cout << c << " ";   
        cout << "\n";
	}
    return 0;
}
	