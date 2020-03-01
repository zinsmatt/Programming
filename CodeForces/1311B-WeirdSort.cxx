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
	ll tt;
	cin >> tt;
	F(t, tt)
	{
		ll n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> p(m);
        vector<bool> pos(n, false);
        F(i, n)
        {
            cin >> a[i];
        }

        F(i, m)
        {
            cin >> p[i];
            pos[p[i]-1] = true;
        }
        //cout << "----------------\n";

        vector<vector<int>> sets;
        F(i, n)
        {   
            if (i == 0)
            {
                sets.push_back(vector<int>(1, a[i]));
            }
            else
            {
                if (pos[i-1])
                {
                    sets.back().push_back(a[i]);
                }
                else
                {
                    sets.push_back(vector<int>(1, a[i]));
                }
            }
        }

        /*for (auto& v : sets)
        {
            for (auto x : v)
            {
                cout << x << " ";
            }
            cout << "\n";
        }*/
        //cout << "----------------\n";
        vector<int> mini, maxi;
        for (auto& v : sets)
        {
            mini.push_back(*min_element(v.begin(), v.end()));
            maxi.push_back(*max_element(v.begin(), v.end()));
        }
        bool ok = true;
        for (int i = 1; i < sets.size(); ++i)
        {
            if (mini[i] < maxi[i-1])
                ok = false;
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";

	}
    

    return 0;
}