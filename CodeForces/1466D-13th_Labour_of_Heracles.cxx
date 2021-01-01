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

std::vector<int> A(26, 0);
char diff(const std::string& s)
{
    fill(A.begin(), A.end(), 0);
    for (auto c : s)
    {
        A[c-'a']=1;
    }
    int i = 0;
    while (i < 26 && A[i])
        ++i;
    return (char)(i+'a');

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
        vector<ll> w(1+n);
        F(i, n) cin >> w[1+i];
        vector<int> deg(n+1, 0);
        vector<int> indices(n);
        std::iota(indices.begin(), indices.end(), 1);
        sort(indices.begin(), indices.end(), [&w](int a, int b) { return w[a] > w[b];});
        F(i, n-1)
        {
            int a, b;
            cin >> a >> b;
            deg[a]++;
            deg[b]++;
        }
        F(i, n) deg[i+1] = std::max(0, deg[i+1]-1);
        //VPRINT("deg ", deg);
        //VPRINT("ord ", indices);
        ll res = 0;
        res = std::accumulate(w.begin(), w.end(), 0ll);
        std::cout << res << " ";
        int idx = 0;
        for (int k = 2; k <= n-1; ++k)
        {

            while (idx < n && deg[indices[idx]] == 0)
                ++idx;
            if (deg[indices[idx]])
            {
                //std::cout << "+ " << indices[idx] << " " << w[indices[idx]] << "\n";
                res += w[indices[idx]];
                deg[indices[idx]]--;
            }
            std::cout << res << " ";
        }
        cout << "\n";

    }
    return 0;
}
