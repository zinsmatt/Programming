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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll tt=1;
    cin >> tt;
    F(ttt, tt)
    {
        ll n, k;
        cin >> n >> k;
        std::vector<ll> h(n);
        F(i, n) cin >> h[i];
        int l = 0, r = 1;
        bool ok = true;
        ll  min = h[0], max = h[0];
        ll cmin, cmax;
        for (int i = 1; i < n; ++i)
        {

            ll cmin = min-k+1;
            ll cmax = max+k-1;

            if (cmin > h[i]+k-1)
            {
                ok = 0;
                break;
            }
            if (cmax < h[i])
            {
                ok = 0;
                break;
            }

            max = std::min(h[i]+k-1, cmax);
            min = std::max(cmin, h[i]);
            //std::cout << i << " === > " << min << " " << max << "\n";
        }

        if (!ok) {

            std::cout << "NO\n";
            continue;
        }


        if (min <= h.back() && h.back() <= max)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }



    }
    return 0;
}