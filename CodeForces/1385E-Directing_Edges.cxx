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
// Recursive function to return gcd of a and b 
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 


vector<char> dfs(vector<vector<int>>& edges, int s, vector<bool>& done)
{
  vector<char> dones;
  F(i, 26)
  {
    if (edges[s][i] && !done[i])
    {
      auto d = dfs(edges, i, done);
      dones.insert(dones.end(), d.begin(), d.end());
    }
  }
  dones.push_back('A'+s);
  done[s] = true;
  return dones;
}

void dfs(int x, const vector<vector<int>>& g, vector<bool>& done, vector<int>& order)
{
	done[x] = true;
	for(auto e : g[x])
	{
		if (!done[e])
			dfs(e, g, done, order);
	}
	order.push_back(x);
}


int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll tt=1;
  cin >> tt;
  F(tti, tt)
  {

    ll n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<pair<int, int>> undir;
    F(i, m)
    {
    	int a, b, t;
    	cin >> t >> a >> b;
    	--a; --b;
    	if (t)
    		g[a].push_back(b);
		undir.push_back({a, b});
    }


    vector<int> order;
    vector<bool> done(n, false);
    F(i, n)
    {
    	if (!done[i])
    		dfs(i, g, done, order);
    }

    reverse(order.begin(), order.end());
    vector<int> pos(n);
    F(i, n)
    {
    	pos[order[i]] = i;
    }
    // VPRINT("order", order)
	// VPRINT("pos", pos)
    bool ok = true;
    F(i, n)
    {
    	for (auto e : g[i])
    	{
    		//cout << "comp " << i << ' ' << e << " ==> " << pos[i] << " " << pos[e] << "\n";
    		if (pos[i] > pos[e]) {
    			ok = false;
    			break;
    		}
    	}
    }

    if (!ok)
    {
    	cout << "NO\n";
    }
    else
    {
    	cout << "YES" << "\n";
    	for (auto [a, b] : undir)
    	{
    		if (pos[a] < pos[b])
    			cout << a+1 << " " << b+1 << "\n";
    		else
    			cout << b+1 << " " << a+1 << "\n";
    	}
    }
}

  return 0;
}
