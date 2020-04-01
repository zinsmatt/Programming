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
		ll n;
		cin >> n;
		vector<int> a(n);
		F(i, n)
		{
			cin >> a[i];
		}

		vector<vector<int>> col(35, vector<int>());
		if (n <= 11)
		{
			cout << n << "\n";
			F(j, n)
			cout << j+1 << " ";
			cout << "\n";
		}
		else
		{
			F(i, n)
			{
				for (int j = 2; j <= 32; ++j)
				{
					if (a[i] % j == 0)
					{
						col[j].push_back(i);
						break;
					}
				}

			}

			vector<int> res(n, -1);
			int cc = 0;
			for (auto& v : col)
			{
				if (v.size() > 0)
				{
					++cc;
				}

				for (auto x : v)
				{
					res[x] = cc;
				}
			}


			cout << cc << "\n";
			for( auto x : res)
				cout << x << " ";
			cout << "\n";

		}

	}


    return 0;
}