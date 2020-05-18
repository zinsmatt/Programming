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

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll tt=1;
  cin >> tt;
  F(tti, tt)
  {

    ll n;
    cin >> n;
    vector<int> a(n);
    F(i, n) cin >> a[i];

    vector<int> s(n+1, 0);
    F(i, n)
    {
      s[i+1] = a[i] + s[i];
    }

    unordered_map<int, int> perf;
    for (ll i = 0; i <= 3162; ++i)
    {
      perf[i*i] = 1;
    }


    ll res = 0;
    F(i, n)
    {
      for (int j = i+1; j < n+1; ++j)
      {
        int d = s[j] - s[i];
        //std::cout << "i j " << i << j << ": " ;
        if (perf.find(d) != perf.end())
        {
          ++res;
          //cout << "GOOD\n";
        }
        else
        {
          //cout << "NO\n";
        }
      }
    }

      cout << "Case #" << tti+1 << ": " << res << "\n";
  }

  return 0;
}

