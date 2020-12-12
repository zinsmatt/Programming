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



std::unordered_map<ll, int> G;



bool f(const std::vector<ll>& a)
{
	if (a.size() == 0)
		return 0;
	ll s = accumulate(a.begin(), a.end(), 0ll);
	
	G[s] = 1;


	ll maxi = std::numeric_limits<ll>::min();
	ll mini = std::numeric_limits<ll>::max();
	for (auto& x : a)
	{
		if (x > maxi) maxi = x;
		if (x < mini) mini = x;
	}

	ll m = (mini + maxi)/2;

	std::vector<ll> left, right;
	for (auto& x : a)
	{
		if (x <= m)
			left.push_back(x);
		else
			right.push_back(x);
	}

	if (left.size() == a.size() || right.size() == a.size())
		return 0;

	if (left.size()) f(left);
	if (right.size()) f(right);
	return 0;
}

int f(const vector<vector<int>>& g, int i)
{
	if (g[i].size() == 0) return 1;
	else
	{
		int res = 0;
		for (auto& e : g[i])
			res = max(res, f(g, e));
		return res + 1;
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
      vector<vector<int>> g(n+1, vector<int>());
      F(i, n)
      {
      	int x;
      	cin >> x;
      	g[x].push_back(i+1);
      }

     cout << f(g, 0)-1 << "\n";

	}
    return 0;
}