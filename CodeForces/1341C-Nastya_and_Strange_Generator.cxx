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
    cout << std::endl;

#define LPRINT(name, l) \
    cout << "list " << name << " : "; \
    for (auto it = l.begin(); it != l.end(); ++it) { \
        cout << *it << " "; \
    } \
    cout << std::endl;

using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
#define INF std::numeric_limits<int>::max()
#define LLINF std::numeric_limits<long long>::max()

#define msign(x, y) ((x<0&&y<0) || (x>0&&y>0))
template <typename T, typename A>
int arg_max(std::vector<T, A> const& vec) {
  return static_cast<int>(std::distance(vec.begin(), max_element(vec.begin(), vec.end())));
}

template <typename T, typename A>
int arg_min(std::vector<T, A> const& vec) {
  return static_cast<int>(std::distance(vec.begin(), min_element(vec.begin(), vec.end())));
}

vector<int> binary2(ll x)
{
	vector<int> res;
	while (x > 0)
	{
		res.push_back(x % 2);
		x >>= 1;
	}
	return res;
}


vector<vector<int>> bfs(vector<vector<pair<int, int>>> const& g, int s, int t)
{
	queue<int> q;
	q.push(s);
	queue<vector<int>> path;
	path.push({});
	vector<bool> done(g.size(), false);
	vector<vector<int>> res;
	while (q.empty() == false)
	{
		int x = q.front();
		q.pop();
		auto p = path.front();
		path.pop();
		done[x] = true;

		if (x == t)
		{
			if (res.size() > 0 && p.size() > res.back().size())
			{
					return res;
			}
			res.push_back(p);
			continue;
		}

		for (auto ee : g[x])
		{
			auto e = ee.first;
			if (!done[e])
			{
				auto cpy = p;
				cpy.push_back(ee.second);
				q.push(e);
				path.push(cpy);
			}
		}
	}
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll tt=1;
    cin >> tt;
    F(tti, tt)
	{
		ll n, k;
		cin >> n;
		vector<int> a(n);
		F(i, n)
		cin >> a[i];

		int l = 0;
		bool ok = true;
		while (l < n-1)
		{
			while (l < n-1 && a[l]+1 == a[l+1])
				++l;
			if (l < n-1)
			{
				if (a[l+1] > a[l]+1)
				{
					ok = false;
					break;
				}
				else
				{
					++l;
				}
			}
		}
		if (ok)
			cout << "Yes\n";
		else
			cout << "No\n";
		


    }

    return 0;
}
