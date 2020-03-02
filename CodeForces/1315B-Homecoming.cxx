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
	ll tt;
	cin >> tt;
	F(t, tt)
	{
		ll a, p, b;
		cin >> a >> b >> p;
		string s;
		cin >> s;
		vector<ll> cost(s.size(), 0);
		ll n = s.size();
		if (s[n-2] == 'A')
			cost[n-2] = a;
		else
			cost[n-2] = b;
		for (int i = s.size()-3; i >= 0; --i)
		{
			if (s[i] == s[i+1])
			{
				cost[i] = cost[i+1];
			}
			else
			{
				if (s[i] == 'A')
					cost[i] = a + cost[i+1];
				else
					cost[i] = b + cost[i+1];
			}
		}
		int i = 0;
		while (i < cost.size() && cost[i] > p)
			++i;
		cout << i+1 << "\n";
	}
    return 0;
}