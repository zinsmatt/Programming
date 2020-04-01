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
    cout << std::endl;

#define LPRINT(name, l) \
    cout << "list " << name << " : "; \
    for (auto it = l.begin(); it != l.end(); ++it) { \
        cout << *it << " "; \
    } \
    cout << std::endl;

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



int main()
{
	ll tt;
	cin >> tt;
	F(t, tt)
	{
		ll n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		vector<int> l(n + 1, -1);


		vector<vector<int>> occs(k+1, vector<int>());
		F(i, k)
		{
			vector<int> occ(26, 0);
			for (int j = i+1; j <= n; j += k)
			{
				auto c = s[j-1];
				//cout << c << " ";
				occ[c-'a']++;
			}
			//cout << "\n";
			//VPRINT("occ ", occ)
			occs[i+1] = occ;
		}

		vector<vector<int>> edges(k+1, vector<int>());
		//cout << "n === "<< n << "\n";
		for (int i = 1; i < n / 2; ++i)
		{
			int b = n+1-i;
			b = ((b-1) % k) + 1;
			int g = ((i-1) % k) + 1;
			if (b != g)
			{
				//cout << "edge " << g << " " <<b << std::endl;
				//cout << "edge " << b << " " <<g << std::endl;
				edges[g].push_back(b);
				edges[b].push_back(g);
			}
		}


		vector<int> groups(k+1, -1);

		vector<int> main_groups;
		for (int i = 1; i < groups.size(); ++i)
		{
			//cout << "start = " << i << "\n";
			if (groups[i] != -1)
				continue;
			queue<int> q;
			int start = i;
			q.push(start);
			while (!q.empty())
			{
				auto x = q.front(); q.pop();

				groups[x] = start;

				if (start != x)
				{
					//cout << " add " << start << " " << x << "\n";
					F(h, 26)
					{
						occs[start][h] += occs[x][h];
					}
				}

				for (auto e : edges[x])
				{
					if (groups[e] == -1)
					{
						groups[e] = start;
						q.push(e);
					}
				}
			}
			main_groups.push_back(i);
			//VPRINT("groups ", groups)

		}
		//VPRINT("groups ", groups)
		//VPRINT("occ[1] = ", occs[1])
		ll res = 0;
		for (auto i : main_groups)
		{
			ll sum = 0;
			ll maxi = 0;
			for (ll x : occs[i])
			{
				sum += x;
				maxi = max(maxi, x);
			}
			//cout << "sum maxi " << sum << " " << maxi << "\n";
			res += sum-maxi;
		}

		cout << res << "\n";

	}


    return 0;
}