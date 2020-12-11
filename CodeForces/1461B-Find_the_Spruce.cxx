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


int maxi(std::vector<std::vector<int>>& g, std::vector<std::vector<int>>& accu, int n, int m, int x, int y)
{
	int rr = x;
	int l = y, r = y;
	int size=0;
	while (1)
	{
		if (l < 0 || r == m || rr == n) break;

		int left = 0;
		if (l>0) left = accu[rr][l-1];
		bool ok = (accu[rr][r]-left) == r-l+1;
		if (!ok) break;
		size++;
		rr++;
		l--;
		r++;
	}
	return size;
}




int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll tt=1;
	cin >> tt;
	F(t, tt)
	{
        int n, m;
        cin >> n >> m;
        std::vector<std::vector<int>> g(n, vector<int>(m, 0));
        std::vector<std::vector<int>> accu(n, vector<int>(m, 0));
        F(i, n)
        {
        	int acc = 0;
        	F(j, m) {
        		char c;
        		cin >> c;
        		if (c == '*'){
        			g[i][j] = 1;
        			acc += 1;
        		}
        		accu[i][j] = acc;
        	}
        }

		ull res = 0;

	    F (i, n) {
	    	F (j, m)
	    	{
	    		ull s = maxi(g, accu, n, m, i, j);
	    		res += s;
	    		//cout << "s = " << s << "\n";
	    		//if (s > 1) res++;
	    		//res += 1;//*(s+1)*(2*s+1)/6;
	    		//cout << "res = " << res << "\n";
	    	}
	    }
	    cout << res << "\n";


	}
    return 0;
}
