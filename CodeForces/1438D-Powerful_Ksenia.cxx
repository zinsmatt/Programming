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
	ll tt=1;
	//cin >> tt;
	F(t, tt)
	{
        int n;
        cin >> n;
        vector<ull> x(n);
        ull tot = 0;
        F(i, n) {
            cin >> x[i];
            tot ^= x[i];
        }

        if (n%2 == 0 && tot) {
            cout << "NO\n";
        }
        else
        {
        
            vector<vector<int>> res;
            if (n%2 == 0) --n;
            for (int i = 1; i <= n-2; i += 2) {
                res.push_back({i, i+1, i+2});
            }
            for (int i = n-4; i >= 1; i-=2) {
                res.push_back({i, i+1, i+2});
            }
            cout << "YES\n";
            cout << res.size() << "\n";
            for (auto& r : res) {
                cout << r[0] << " " << r[1] << " " << r[2] << "\n";
            }
        }
	}
    return 0;
}