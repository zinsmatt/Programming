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

vector<int> binary2(ll x)
{
	vector<int> res;
	while (x > 0)
	{
		res.push_back(x % 2);
		x >>= 1;
	}
	return res;
}

bool check_double(vector<int>& v)
{
	F(i, v.size())
	{
		auto x = abs(v[i])-1;
		if (v[x] < 0)
			return true;
		else
			v[x] *= -1;
	}
	return false;
}

int main()
{
	ll tt;
	cin >> tt;
	F(tti, tt)
	{
		ll n;
		cin >> n;

		vector<vector<int>> M(n, vector<int>(n, 0));
		vector<vector<int>> N(n, vector<int>(n, 0));

		ll t = 0;
		F(i, n)
		{
			F(j, n)
			{
				cin >> M[i][j];				
				N[j][i] = M[i][j];
				if (i == j)
				{
					t += M[i][j];
				}
			}
		}

		ll r = 0, c = 0;
		F(i, n)
		{
			r += check_double(M[i]);
			c += check_double(N[i]);
		}

		cout << "Case #" << tti+1 <<": " << t << " " << r << " " << c << "\n";

	}

	
    return 0;
}
