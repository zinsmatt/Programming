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
    	string s;
    	cin >> s;
    	vector<vector<int>> g(26, vector<int>(26, 0));
    	for (int i = 0; i < s.size() -1; ++i)
    	{
    		g[s[i]-'a'][s[i+1]-'a'] = 1;
    		g[s[i+1]-'a'][s[i]-'a'] = 1;
    	}
    	bool ok = true;
    	vector<int> one;
    	int nb_two = 0;
    	for (int i = 0; i < g.size(); ++i)
    	{
    		int count = 0;
    		for (int j = 0; j < 26; ++j)
    		{
    			if (g[i][j] == 1)
    				++count;
    		}
    		if (count > 2)
    		{
    			ok = false;
    			break;
    		}
    		else if (count == 1)
    		{
				one.push_back(i);
    		}
    		else
    		{
    			nb_two++;
    		}
    	}

    	if (s.size() == 1)
    	{
    		cout << "YES\nazertyuiopmlkjhgfdsqwxcvbn\n";
    	}
    	else if (!ok || one.size() != 2)
    	{
    		cout << "NO\n";
    	}
    	else
    	{
    		cout << "YES\n";
    		std::queue<int> q;
    		q.push(one[0]);
    		vector<bool> occ(26, false);
    		while (q.size() > 0)
    		{
    			auto x = q.front();
    			q.pop();
    			occ[x] = true;
    			cout << (char)(x + 'a');

    			for (int j = 0; j < 26; ++j) {
    				if (g[x][j] && !occ[j]) {
    					q.push(j);
    				}
    			}
    		}
    		for (int i = 0; i < 26; ++i) {
    			if (!occ[i]) {
    				cout << (char)(i + 'a');
    			}
    		}
    		cout << "\n";
    	}
    }
	

    return 0;
}