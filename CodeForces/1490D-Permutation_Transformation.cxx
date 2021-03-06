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

void solve(const std::vector<int>& arr, int l, int r, unordered_map<int, int>& depths, int depth)
{
    if (r < l) return;
    int k = l;
    int max = arr[k];
    int max_i = l;
    while (k <= r) {
        if (arr[k] > max) {
            max = arr[k];
            max_i = k;
        }
        ++k;
    }
    depths[arr[max_i]] = depth;

    solve(arr, l, max_i-1, depths, depth+1);
    solve(arr, max_i+1, r, depths, depth+1);
}


int main()
{
	ll tt=1;
	cin >> tt;
	F(t, tt)
	{
        int n;
        cin >> n;
        std::vector<int> arr(n);
        F (i, n) cin >> arr[i];

        std::unordered_map<int, int> depths;
        solve(arr, 0, n-1, depths, 0);
        for (auto x : arr) cout << depths[x] << " ";
        cout << "\n";

	}
    

    return 0;
}