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
    
	ll n, m;
	cin >> n >> m;
	std::vector<string> s(n);
	vector<pair<int, int>> sym;
	string uniform="";
	unordered_map<string, int> map;
	F(i, n)
	{
		cin >> s[i];
		std::string rev = s[i];
		std::reverse(rev.begin(), rev.end());
		if (rev == s[i])
		{
			if (rev.size() > uniform.size())
				uniform = rev;
		}
		else
		{
			if (map.find(rev) != map.end())
			{
				sym.emplace_back(map[rev], i);
			}
			else
			{
				map[s[i]] = i;
			}
		}
	}
	string res;
	res = uniform;
	for (auto& p : sym)
	{
		res = s[p.first] + res + s[p.second]; 
	}
	cout << res.size() << "\n" << res << "\n";

    return 0;
}