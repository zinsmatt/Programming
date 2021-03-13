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



int main()
{
	ll tt=1;
	cin >> tt;
	F(t, tt)
	{
        std::set<ll> ms;
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        F (i, n) {
            ll x;
            cin >> x;
            ms.insert(x);
        }
        
        auto it = ms.begin();
        int i = 0;
        while (it != ms.end() && i == *it) {
            ++it;
            ++i;
        }

        if (it == ms.end()) {
            std::cout << ms.size() + k << "\n";
        } else {
            auto max = *(--ms.end());
            if (k > 0)
                ms.insert(std::ceil(static_cast<double>(i+max)/2));
            std::cout << ms.size() << "\n";
        }
        

	}
    

    return 0;
}