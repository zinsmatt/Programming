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

struct hash_pair {
	size_t operator()(const pair<int, int>& p) const
	{
		auto hash1 = hash<int>{}(p.first);
		auto hash2 = hash<int>{}(p.second);
		return hash1 ^hash2;
	}
};

int main()
{
    
    ll tt;
    cin >> tt;
    F(t, tt)
    {
    	ll n;
    	cin >> n;
    	string s;
    	cin >> s;	
    	unordered_map<pair<int, int>, int, hash_pair> map;
    	map[make_pair(0, 0)] = 0;
    	pair<int, int> x = {0, 0};
    	int time = 0;
    	int l, r, min_t = INF;
    	for (auto& u : s)
    	{
    		if (u == 'L') {
    			x.first--;
    		} else if (u == 'R') {
    			x.first++;
    		} else if (u == 'U') {
    			x.second++;
    		} else {
    			x.second--;
    		}
    		++time;
    		if (map.find(x) != map.end())
    		{
    			if ((time - map[x] + 1) < min_t)
    			{
    				min_t = time - map[x] + 1;
    				l = map[x];
    				r = time-1;
    			}
    		}
    		map[x] = time;
    	}
    	if (min_t < INF)
    	{
    		cout << l + 1 << " " << r + 1 << std::endl;
    	}
    	else
    	{
    		cout << "-1\n";
    	}

    }
	

    return 0;
}