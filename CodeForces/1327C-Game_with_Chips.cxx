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




int main()
{
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> src(k, vector<int>(2, 0));
	vector<vector<int>> dst(k, vector<int>(2, 0));
	vector<vector<int>> vec(k, vector<int>(2, 0));
	F(i, k)
	{
		int x, y;
		cin >> x >> y;
		src[i][0] = x;
		src[i][1] = x;
	}

	vector<int> max_V(m*2+1, -INF);
	vector<int> min_V(m*2+1, INF);
	vector<int> dx_pos();
	vector<int> dx_neg();

	F(i, k)
	{
		int x, y;
		cin >> x >> y;
		dst[i][0] = x;
		dst[i][1] = x;

		vec[i][0] = dst[i][0] - src[i][0];
		vec[i][1] = dst[i][1] - src[i][1];

		//if (vec[i][0] >= 0)
		//{
		//	dx_pos.emplace_back(vec[i][0]);
		//}
		//else
		//{
		//	dx_neg.emplace_back(vec[i][0]);
		//}
	}

	//sort(dx_neg.begin(), dx_neg.end(), std::greater<int>());
	//sort(dx_pos.begin(), dx_pos.end());
//
//	//F(i, k)
//	//{
//	//	auto v = vec[i][0];
//	//	max_V[v+m] = max(max_V[v+m], vec[i][1]);
//	//	min_V[v+m] = min(min_V[v+m], vec[i][1]);
	//}

	stringstream s;
	/*int x = 0;
	for (auto dx = dx_pos)
	{
		F(j, dx - x)
		{
			s << "L";
		}

	}*/

	int iter = 0;
	F(dy, n-1)
		{
			if (iter % 2 == 0)
			{
				s << "D";
			}
			else
			{
				s << "U";
			}
		}	
	++iter;
	F(dx, m-1)
	{
		s << "L";
		F(dy, n-1)
		{
			if (iter % 2 == 0)
			{
				s << "D";
			}
			else
			{
				s << "U";
			}
		}	
		++iter;
	}
	F(dy, n-1)
		{
			if (iter % 2 == 0)
			{
				s << "D";
			}
			else
			{
				s << "U";
			}
		}	
	++iter;
	F(dx, m-1)
	{
		s << "R";
		F(dy, n-1)
		{
			if (iter % 2 == 0)
			{
				s << "D";
			}
			else
			{
				s << "U";
			}
		}	
		++iter;
	}
	string res = s.str();
	cout << res.size() << "\n";
	cout << res << "\n";
    return 0;
}