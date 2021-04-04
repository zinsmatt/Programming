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
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
	ll tt;
	cin >> tt;
	F(t, tt)
	{
		int n;
		cin >> n;
		vector<ll> a(n);
		std::map<ll, int> m;
		F (i, n) {
			cin >> a[i];
			if (m.find(a[i]) != m.end())
				m[a[i]]++;
			else
				m[a[i]] = 1;
		}

		std::priority_queue<std::pair<int, ll>> q;
		for (auto& p : m) {
			q.push({p.second, p.first});
		}

		while (q.size() >= 2) {
			auto x = q.top();
			q.pop();
			auto y = q.top();
			q.pop();
			//std::cout << "rm " << x.second << " " << y.second << "\n";
			x.first--;
			y.first--;
			if (x.first) 
				q.push(x);
			if (y.first)
				q.push(y);
			//std::cout << q.size() << std::endl;
		}

		int res = 0;
		if (!q.empty())
			res += q.top().first;
		std::cout << res << "\n";
	}
    

    return 0;
}
