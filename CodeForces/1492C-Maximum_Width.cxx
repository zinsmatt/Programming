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
	// cin >> tt;
	F(t, tt)
	{
        int n, m;
        cin >> n >> m;
        std::string a, b;
        cin >> a >> b;

        vector<int> left;
        int i = 0;
        for (auto c : b)
        {
            while (a[i] != c) ++i;
            left.push_back(i);
            ++i;
        }

        vector<int> right;
        i = a.size()-1;
        for (int j = b.size()-1; j >= 0; --j) {
            while (a[i] != b[j]) --i;
            right.push_back(i);
            --i;
        }
        std::reverse(right.begin(), right.end());
        int res = 0;
        for (int i = 1; i < left.size(); ++i)
        {
            res = std::max(res, right[i]-left[i-1]);
        }
        std::cout << res << "\n";
	}
    

    return 0;
}