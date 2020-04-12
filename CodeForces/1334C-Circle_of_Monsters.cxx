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

		//vector<ll> a(n, 0), b(n, 0);
		ll a0, b;

		ll tot = 0;
		ll mini = LLINF;
		ll d = 0;
		F(i, n)
		{
			ll aa;
			cin >> aa;
			if (i > 0)
			{
				d = max(0ll, aa-b);
				tot += d;
				mini = min(aa-d, mini);
			}
			else
			{
				a0 = aa;
			}
			cin >> b;

		}
		d = max(0ll, a0-b);
		tot += d;
		mini = min(a0-d, mini);
		//F(i, n)
		//{
		//	int prev = i-1;
		//	if (prev < 0)
		//		prev += n;
		//	auto d = max(0ll, a[i] - b[prev]);
		//	tot += d;
		//	a[i] -=d;
		//	mini = min(mini, a[i]);
		//}

		cout << tot + mini  << "\n";

		
	
	}

    return 0;
}
