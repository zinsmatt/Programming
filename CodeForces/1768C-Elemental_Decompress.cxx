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

ull fact(ull x) {
    if (x == 0)
    return 1;
    return x * fact(x-1);
}

int main()
{
    int t;
    cin >> t;
    F (tt, t)
    {
        ull n;
        cin >> n;
        vector<int> v(n);
        vector<int> cnt(n+1, 0);
        vector<vector<int>> inds(n+1, vector<int>());
        F (i, n) {
            int x;
            cin >> v[i];
            ++cnt[v[i]];
            inds[v[i]].push_back(i);
        }

        int ok = 1;
        for (auto x : cnt)
            if (x > 2)
                ok = 0;
        if (cnt[1] > 1)
            ok = 0;
        
        
        vector<int> out(n);
        vector<int> out2(n);
        stack<int> free;
        int i = 1;
        while (i <= n) {
            if (cnt[i] == 1) {
                out[inds[i][0]] = i;
                out2[inds[i][0]] = i;
            } else if (cnt[i] == 0) {
                free.push(i);
            } else {
                if (free.size() > 0) {
                    out[inds[i][0]] = i;
                    out[inds[i][1]] = free.top();
                    out2[inds[i][0]] = free.top();
                    out2[inds[i][1]] = i;
                    free.pop();
                } else {
                    ok = 0;
                    break;
                }
            }
            ++i;
        }

        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            
            for (auto x : out) cout << x << " ";
            cout << "\n";
            for (auto x : out2) cout << x << " ";
            cout << "\n";
            
        }

    }

    return 0;
}
