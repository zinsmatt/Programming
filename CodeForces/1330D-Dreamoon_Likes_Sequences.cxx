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


/*


1
536870908 999825269

*/
int main()
{
	ll tt;
	cin >> tt;
	F(t, tt)
	{

		ll d, m;
		cin >> d >> m;

		ll max = std::floor(log2((double)d))-1;
		while (pow(2ll, max) <= d)
			++max;

		vector<ll> groups_size(max);
		F(i, max)
		{
			groups_size[i] = (ll)pow(2, i);
		}

		//cout << "d = " << d << "\n";
		//cout <<  "  (1ll << (max-1)) = " <<  (1ll << (max-1)) << "\n";
		groups_size[groups_size.size()-1] = d - (1ll << (max-1)) + 1;
		//VPRINT("size ", groups_size)



		// True but too slow
		/*
		ll total=0;
		for (int b = 1; b < (ll)pow(2, max); ++b)
		{
			int c = b;
			ll t = 1;
			int iter = 0;
			while (c > 0)
			{
				if (c % 2) {
					t *= groups_size[iter];
					t %= m;
				}
				c >>= 1;
				++iter;
			}
			total += t;
			total %= m;
		}

		cout << total << "\n";
		*/

		//VPRINT("size: ", groups_size)

		ll res = 1;
		for (auto s : groups_size)
		{
			res = (res * (s+1)) % m;
		}
		res -= 1;
		if (res < 0)
			res += m;
		cout << res << "\n";




		//cout << ((d % m) * ((d+1)%m))%m / 2 << std::endl;

		/*ll nb_combin = 1;
		F(i, max)
		{
			nb_combin *= groups_size[i]%m;
			nb_combin = nb_combin % m;
		}

		ll temp = 1;
		F(i, max)
		{
			temp = (temp *2) % m;
		}

		ll res = (nb_combin * temp) % m - nb_combin;*/

//		cout << res << "\n";
	
	}

	
    return 0;
}
