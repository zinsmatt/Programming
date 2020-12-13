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


void solve(const vector<vector<int>>& a, vector<int>& indices, int i)
{
	if (indices[i] >= a[i].size())
		return;
	else {
		while (indices[i] < a[i].size())
		{
			int x = a[i][indices[i]];
			cout << "A " << x << "\n";
			indices[i]++;
			solve(a, indices, x);
			cout << "R " << x << "\n";
		}

	}
}



int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll tt=1;
	//cin >> tt;
	F(t, tt)
	{
      ll n;
      cin >> n;
      vector<vector<int>> a(n+1);
      F(i, n+1)
      {
      	int m;
      	cin >> m;
      	vector<int> t(m);
      	F(j, m)
      		cin >> t[j];
      	a[i] = t;
      }

      vector<int> indices(n+1, 0);

      int i = 0;
      solve(a, indices, 0);

	}
    return 0;
}