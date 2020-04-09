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

	ll tt;
	cin >> tt;
	F(tti, tt)
	{ 
		ll n;
		cin >> n;
		vector<ll> a(n), b(n);
		vector<bool> minus(n, false), plus(n, false);
		bool m = false, p = false;
		F(i, n){
			cin >> a[i];
			minus[i] = m;
			plus[i] = p;
			if (a[i] == 1)
				p = true;
			if (a[i] == -1)
				m = true;
		}
		F(i, n)
		{
			cin >> b[i];
		}

		bool res = true;
		F(i, n)
		{
			if (a[i] == b[i] || (a[i] < b[i] && plus[i]) || (a[i] > b[i] && minus[i]))
			{

			}else
			{
				res = false;
			}
		}
		if (res)
			cout << "YES\n";
		else cout << "NO\n";


	}

    return 0;
}
