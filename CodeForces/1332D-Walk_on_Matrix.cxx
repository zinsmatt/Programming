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


vector<int> d(ll x)
{
	vector<int> res;
	while (x > 0)
	{
		auto r = x % 2;
		res.push_back(r);
		x = (x-r) / 2;
	}
	return res;
}

int main()
{
	ll k;
	cin >> k;

	if (k == 0)
	{
		cout << "1 1\n1\n";
		return 0;
	}

	auto r = d(k);

	auto b = pow(2, r.size());
	auto a = b-1;
	auto s = a - k;

	auto o = a + b;









	vector<vector<ll>> m(3, vector<ll>(3, 0));

	m[0][0] = o;
	m[0][1] = a;
	m[0][2] = a;

	m[1][0] = b;
	m[1][1] = a;
	m[1][2] = s;

	m[2][0] = b;
	m[2][1] = o;
	m[2][2] = a;

	cout << "3 3\n";
	for (auto v : m)
	{
		for (auto vv : v)
		{
			cout << vv << " ";
		}
		cout << "\n";
	}



	
    return 0;
}