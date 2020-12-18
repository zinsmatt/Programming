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

ll find(std::map<ll, ll>& m, ll t)
{
    auto ub = m.upper_bound(t);
    auto ub1 = ub;
    ub1--;
    ll dt = t - ub1->first;
    if (ub->second >= ub1->second) {
        return min(ub->second, ub1->second + dt);
    } else {
        return max(ub->second, ub1->second - dt);
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll tt=1;
    cin >> tt;
    F(ttt, tt)
    {
        ll n;
        cin >> n;

        vector<ll> ti(n), xi(n);
        F(i, n) {
            cin >> ti[i] >> xi[i];
        }

        std::map<ll, ll> m;

        ll x = 0;
        ll t_end = 0;
        m[0] = x;
        F (i, n)
        {
            if (ti[i] >= t_end) {
                m[ti[i]] = x;
                t_end = ti[i] + std::abs(xi[i] - x);
         //       cout << "t_end = " << t_end << "\n";
                x = xi[i];
            }
        }
        if (t_end != 0) {
            m[std::numeric_limits<ll>::max()] = x;
        }

        //cout << "m \n";
        //for (auto p : m)
        //{
        //    cout << p.first << " " << p.second << "\n";
        //}

        ti.push_back(std::numeric_limits<ll>::max());
        ll res = 0;
        ll x_high_prev = 0;
        F (i, n)
        {
            ll X = xi[i];
            //cout << "time range = " << ti[i] << " " << ti[i+1] << " X = " << X << "\n";
            ll x_low;
            if (i == 0) x_low = find(m, ti[i]);
            else x_low = x_high_prev;
            auto x_high = find(m, ti[i+1]);
            //cout << "xlow = " << x_low << "  xhigh = " << x_high << "\n";

            if (min(x_high, x_low) <= X && X <= max(x_low, x_high))
                ++res;
            x_high_prev = x_high;
        }
        cout << res << "\n";
    }
    return 0;
}