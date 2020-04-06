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
	//cin >> tt;
	tt = 1;
	F(t, tt)
	{
		ll n, m;
		cin >> n >> m;

		vector<ll> l(m);
		F(i, m)
		{
			cin >> l[i];
		}

		int p = n+1; //start of next one
		vector<ll> res;
		bool ok =true;
		for (int i = m-1; i >= 0; --i)
		{


			// we have p-1 case
			// requires at least

			ll new_p = p - l[i];
			//cout << "new p " << new_p << "\n";
			// reste new_p case
			// need i

			ll shift = max(0ll, i+1-new_p);
			shift = min(shift, min(n+1 - (new_p + l[i]), l[i]-1));

			//cout << "shift " << shift << "\n";

			new_p += shift;
			//cout << "new p after shift " << new_p << "\n";


			res.push_back(new_p);
			p = new_p;
		}
		//cout << "p " << p << "\n";
		if (!ok || p != 1)
		{
			cout << "-1\n";
		}
		else
		{
			reverse(res.begin(), res.end());
			for (auto x : res)
				cout << x << " ";
			cout << "\n";
		}
	}

	
    return 0;
}
