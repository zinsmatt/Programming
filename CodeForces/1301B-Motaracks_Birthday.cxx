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
    	ll n;
    	cin >> n;
    	vector<ll> a(n);
    	ll maxi = -LLINF, mini = LLINF;
    	ll max_diff = -LLINF;
    	F(i, n)
    	{
    		cin >> a[i];
    		if (i > 0)
    		{
    			if (a[i] == -1 && a[i-1] != -1)
    			{
    				maxi = max(maxi, a[i-1]);
    				mini = min(mini, a[i-1]);    				
    			}
    			else if (a[i-1] == -1 && a[i] != -1)
    			{
    				maxi = max(maxi, a[i]);
    				mini = min(mini, a[i]);    					
    			}
    			else
    			{
    				max_diff = max(max_diff, abs(a[i] - a[i-1]));
    			}
    		}
    	}
    	int k = (maxi + mini) / 2;
    	int m = max(maxi - k, max_diff);
    	cout << m << " " << k << "\n";

    }
	

    return 0;
}