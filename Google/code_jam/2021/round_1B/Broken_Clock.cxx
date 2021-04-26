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

bool suffi(vector<ll>& need, vector<ll>& prov)
{
    F (i, need.size())
    {
        if (need[i]>prov[i])
        return false;
    }
    return true;
}

vector<ll> add(vector<ll>& a, vector<ll>& b)
{
    vector<ll> res = a;
    F (i, a.size())
    res[i] += b[i];
    return res;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::unordered_map<string, vector<ll>> map;

    for (ll x = 0; x < 12*60*60; ++x) {
        auto t = x;
        auto h = t / 3600;
        t %= 3600;
        auto m = t / 60;
        auto s = t % 60;


        auto angle_h = x * 1000000000;
        auto angle_m = (x * 1000000000 * 12) % 43200000000000;
        auto angle_s = (x * 1000000000 * 12 * 60) % 43200000000000;

        vector<ll> angles = {angle_h, angle_m, angle_s};
        F (k, 3)
        {
            auto x = angles[0] - angles[k];
            auto y = angles[1] - angles[k];
            auto z = angles[2] - angles[k];

            if (x < 0) x += 43200000000000;
            if (y < 0) y += 43200000000000;
            if (z < 0) z += 43200000000000;

            vector<ll> temp = {x, y, z};
            sort(temp.begin(), temp.end());
            string key = std::to_string(temp[0]) + std::to_string(temp[1]) + std::to_string(temp[2]);
            map[key] = {h, m, s};
        }
    }

	ll tt=1;
	cin >> tt;
	F(t, tt)
	{
        vector<ll> abc(3);
        F (i, 3) cin >> abc[i];
        
        auto d = *std::min_element(abc.begin(), abc.end());
        abc[0] -= d;
        abc[1] -= d;
        abc[2] -= d;

        
        sort(abc.begin(), abc.end());
        string key = std::to_string(abc[0]) + std::to_string(abc[1]) + std::to_string(abc[2]);
        auto r = map[key];
        cout << "Case #" << t+1 << ": " << r[0] << " " << r[1] << " " << r[2] << " 0\n";
    }
    return 0;
}