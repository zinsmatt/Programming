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
		ll n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<int> stops(m);
		F(i, m) {
			cin >> stops[i];
		}

		vector<vector<int>> occ(n, vector<int>(26, 0));
		F(i, n)
		{
			if (i > 0)
			{
				occ[i] = occ[i-1];
			}
			++occ[i][s[i]-'a'];
		}
		stops.push_back(n);

		vector<int> res(26, 0);
		F(i, stops.size())
		{
			auto& v = occ[stops[i]-1];
			std::transform(res.begin(), res.end(), v.begin(), res.begin(), std::plus<int>());
		}
		for (auto r : res)
			cout <<  r << " ";
		cout << "\n";


	}
    return 0;
}