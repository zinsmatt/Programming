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
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


	ll tt=1;
	cin >> tt;
	F(tti, tt)
	{ 
		ll n;
		cin >> n;
		vector<ll> a(n);
		F(i, n)
			cin >> a[i];
		sort(a.begin(), a.end());

		int l,r;
		if (n % 2 == 0)
		{
			r = n/2;
			l = r-1;
		}
		else
		{
			int m = n/2;
//			res[i++] = a[m];
			l = m;// -1;
			r = m;// +1;
		}

		vector<ll> res(n);
		int i = 0;
		while (r < n&& r >= 0)
		{
			if (r == l)
				res[i++] = a[r];
			else
			{
				res[i++] = a[l];
				res[i++] = a[r];
			}
			++r;
			--l;
		}
		F(j, n)
		{
			cout << res[j];
			if (j <n-1)
				cout << " ";
		}
		cout << "\n";
		
	
	}

    return 0;
}
