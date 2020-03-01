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
	//cin >> tt;
    tt = 1;

	F(t, tt)
	{
		ll n;
        cin >> n;
        vector<int> a(n);
        F(i, n) {
            cin >> a[i];
        }
        int maxi_i = distance(a.begin(), max_element(a.begin(), a.end()));
        bool ok = true;
        int i = maxi_i;
        while (i > 0)
        {
            if (a[i-1] > a[i]) {
                ok = false;
                break;
            }
            --i;
        }
        if (ok)
        {
            i = maxi_i;
            while (i < n-1)
            {
                if (a[i] < a[i+1]) {
                    ok = false;
                    break;
                }
                ++i;
            }
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
	}

    return 0;
}