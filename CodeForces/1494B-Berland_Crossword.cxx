// This is just a template solution used as initial script


#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>     /* abs */

 
#define F(i, n) for (ll i = 0; i < n; ++i)

#define VPRINT(name, v) \
    cout << name << " : "; \
    for (const auto& e : v) { \
        cout << e << " "; \
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

#define A(x) ((x >> 3) & 1)
#define B(x) ((x >> 2) & 1)
#define C(x) ((x >> 1) & 1)
#define D(x) ((x >> 0) & 1)

int main()
{
	ll tt=1;
	cin >> tt;
	F(t, tt)
	{
        ll n, U, R, D, L;
        cin >> n >> U >> R >> D >> L;


        bool good = false;
        for (int i = 0; i < 16; ++i) {
            good = true;
            ll u = 0, r = 0, d = 0, l = 0;

            u += A(i) + B(i);
            r += B(i) + C(i);
            d += C(i) + D(i);
            l += D(i) + A(i);
           
            if (u > U || u+n-2 < U) good = false;
            if (r > R || r+n-2 < R) good = false;
            if (d > D || d+n-2 < D) good = false;
            if (l > L || l+n-2 < L) good = false;
            if (good)
                break;
        }

        if (good)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";    
	}
    

    return 0;
}