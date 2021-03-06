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
		ll n, k;
		cin >> n >> k;
		std::string s;
		cin >> s;
		ll min_i = n+1, max_i = 0;
		F (i, n) {
			if (s[i] == '*') {
				min_i = std::min(min_i, i);
				max_i = std::max(max_i, i);
			}
		}

		if (min_i == max_i) {
			std::cout << "1\n";
		} else {
			int i = min_i;
			int c = 0, last_i;
			while (i <= max_i) {
				int j = 0;
				while (i <= max_i && j < k) {
					++i;
					++j;
					if (s[i] == '*')
						last_i = i;
				}
				if (i < max_i) {
					i = last_i;
					c++;
				}
			}

			std::cout << 2 + c << "\n";
		}
		
	}
    

    return 0;
}
