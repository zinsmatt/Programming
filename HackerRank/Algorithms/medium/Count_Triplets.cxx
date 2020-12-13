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


    std::ifstream file("input1.txt");
    ll tt=1;
    //cin >> tt;
    F(t, tt)
    {
        ll n, k;
        file >> n >> k;

        vector<int> arr(n);
        unordered_map<ll, ll> r, l;
        F(i, n)
        {
            int x;
            file >> x;
            if (r.find(x) == r.end())
                r[x] = 1;
            else
                r[x]++;
            arr[i] = x;
        }



        ll res = 0;
        if (k == 1)
        {
            for (auto& it : r)
            {
                if (it.second > 2)
                {
                    res += it.second * (it.second-1) * (it.second-2) / 6;
                }
            }
        }
        else
        {

            for (auto& x : arr)
            {
                // remove from right
                if (r.find(x) != r.end() && r[x] > 0)
                    r[x]--;

                ll v1 = 0, v2 = 0;
                ll x1 = x / k;
                ll x3 = x * k;
                if (l.find(x1) != l.end())
                    v1 += l[x1];
                if (r.find(x3) != r.end())
                    v2 += r[x3];
                if (x % k == 0)
                    res += v1 * v2;

                // add to left
                if (l.find(x) != l.end())
                    l[x]++;
                else
                    l[x] = 1;
            }
        }

        cout << res << "\n";
    }
    file.close();
    return 0;
}
