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





int solve(std::unordered_map<ll, ll>& m, int x)
{
    if (m.find(x) != m.end())
        return m[x];
    ll res;
    if (x % 2 == 0)
    {
        res = (x+1)*(x+1) - solve(m, x-1) - solve(m, x-2);
    }
    else
    {
        res = ((x+2)*(x+2))/2;
    }

    m[x] = res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll tt=1;
    cin >> tt;
    F(ttt, tt)
    {
        ll x;
        cin >> x;
        while (1)
        {
            std::string s = std::to_string(x);
            ll r = 0;
            ll maxi = 0;
            F (i, s.size())
            {
                if (s[i] != '0')
                {
                    //r = std::gcd(r, (ll)(s[i]-'0'));
                    ll d = x % (ll)(s[i]-'0');
                    maxi=std::max(maxi, d);
                }
            }
            if (maxi == 0)
                break;
            x += 1;
        }
        cout << x << "\n";

    }
    return 0;
}
