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

#define msign(x, y) ((x<0&&y<0) || (x>0&&y>0))
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
		ll n, k;
		cin >> n >> k;
		vector<ll> a(n, 0);
		ll t=0;

		F(i, n)
		{
			cin >> a[i];
			t += a[i];		
		}

		vector<vector<ll>> ranges(n/2, vector<ll>(2));
		ll mini = INF, maxi = 0;
		unordered_map<int, int> s;
		F(i, n/2)
		{
			ranges[i][0] = min(a[i], a[n-1-i]) + 1;
			ranges[i][1] = max(a[i], a[n-1-i]) + k;
			auto su  = a[i] + a[n-1-i];
			if (s.find(su) == s.end())
				s[su] = 1;
			else s[su]++;
		}
		vector<pair<int, int>> sums;
		for (auto p : s)
		{
			sums.push_back(p);
		}
		sort(sums.begin(), sums.end(), [](auto const& a, auto const& b) {
			return a.second > b.second;
		});



		ll res = n/2;
		//cout << "mini maxi " << mini << " " << maxi << "\n";
		//for (int m = mini; m<= maxi ; ++m)
		//F(j, n/2)
		for (auto& e : sums)
		{
			auto m = e.first;
			//int m = a[j] + a[n-1-j];
			bool stop = true;
			ll cost = 0;
			F(i, n/2)
			{
				if (a[i] + a[n-1-i] == m)
					cost += 0;
				else if (ranges[i][0] <= m && m <= ranges[i][1])
					cost += 1;
				else{
				cost += 2;
					stop = false;	
				} 
			}
			res = min(res, cost);
			if (stop)
				break;
		}

		cout << res << "\n";	


    }

    return 0;
}
