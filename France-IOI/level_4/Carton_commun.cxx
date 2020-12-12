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



int f(const vector<int>& a, int i, vector<int>& out)
{
	out.push_back(i);
	if (i == 0)
	{
		return 0;
	}
	else
	{
		return f(a, a[i], out);
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
      vector<int> a(n+1);
      F(i, n)
      {
      	cin >> a[i+1];
      }

      int m;
      cin >> m;
      F(i, m)
      {
      	int x, y;
      	cin >> x >> y;
      	vector<int> xx, yy;
      	f(a, x, xx);
      	f(a, y, yy);
      	vector<int> contain(n+1, 0);
      	for (auto& v : xx)
      		contain[v] = 1;
      	int j = 0;
      	while (contain[yy[j]] == 0)
      		++j;
      	cout << yy[j] << "\n";
      }




	}
    return 0;
}