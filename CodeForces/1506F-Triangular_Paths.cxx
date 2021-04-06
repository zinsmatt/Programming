// This is just a template solution used as initial script


#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>     /* abs */

 
#define F(i, n) for (ll i = 0; i < n; ++i)

#define VPRINT(name, v) \
    cout << name << " : "; \
    for (const auto& e : v) { \
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


int find(std::vector<int>& sets, int x) {
    if (sets[x] == -1) return x;
    else {
        auto ret = find(sets, sets[x]);
        sets[x] = ret;
        return ret;
    }
}

void union_(std::vector<int>& sets, int x, int y) {
    auto root_x = find(sets, x);
    auto root_y = find(sets, y);
    if (root_x != root_y) {
        sets[root_y] = root_x;
    }
}





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll tt=1;
	cin >> tt;
	F(t, tt)
	{
        int n;
        cin >> n;
        vector<pair<ll, ll>> pts(n);
        F (i, n) cin >> pts[i].first;
        F (i, n) cin >> pts[i].second;

        pts.push_back({1, 1});
        sort(pts.begin(), pts.end());

        ll total_cost = 0;
        for (int i = 1; i < pts.size(); ++i) 
        {
            //std::cout << pts[i-1].first << " " << pts[i-1].second << " => " << pts[i].first << " " << pts[i].second << "\n";
            auto odd = (pts[i-1].first+pts[i-1].second) % 2;
            auto ecart = (pts[i].first - pts[i].second) - (pts[i-1].first - pts[i-1].second);
            auto cost_1 = (odd + ecart) / 2;
            pts[i-1].first += ecart;
            auto even = (pts[i-1].first+pts[i-1].second + 1) % 2;
            auto cost_2 = (pts[i].first - pts[i-1].first) * even;
            if (ecart > 0) cost_2 = 0;
            //std::cout << "cost_1 = " << cost_1 << "   cost_2 = " << cost_2 << "\n";
            total_cost += cost_1 + cost_2;
        }
        std::cout << total_cost << "\n";


    }

    return 0;
}