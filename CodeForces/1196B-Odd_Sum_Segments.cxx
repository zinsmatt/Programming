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
    
	ll tt;
	cin >> tt;
	F(t, tt)
	{
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll imp = 0;
        F(i, n) {
            cin >> a[i];
            if (a[i] % 2 == 1)
                imp++;

        }

        if (imp >= k && (imp - k) % 2 == 0)
        {
            cout << "YES\n";
            int r = 0;
            for (int i = 0; i < n && r < k-1; ++i)
            {
                if (a[i] % 2 == 1)
                {
                    cout << i+1 << " ";
                    ++r;
                }
            }
            cout << n << "\n";
        }
        else
        {
            cout << "NO\n";
        }
	}

    return 0;
}