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



int main()
{

	ll tt=1;
	cin >> tt;
	F(tti, tt)
	{ 
		ll n;
		cin >> n;
		vector<int> p(n), c(n);
		F(i, n)
		{
			cin >> p[i];
			cin >> c[i];
		}

		bool ok = true;
		F(i, n)
		{
			if (p[i] < c[i])
				ok = false;
		}
		for (int i = 1; i < n; ++i)
		{
			if (c[i]-c[i-1] > p[i]-p[i-1])
				ok = false;
			if (c[i] < c[i-1] || p[i] < p[i-1])
				ok = false;
		}

		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";




	
	}

    return 0;
}
