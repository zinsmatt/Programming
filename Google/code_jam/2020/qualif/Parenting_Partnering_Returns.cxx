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
		ll av[2] = {0, 0};

		vector<pair<int, int>> act(n, pair<int, int>());

		F(i, n)
		{
			int s, e;
			cin >> s >> e;
			act[i] = {s, e};
		}


		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);

		sort(ind.begin(), ind.end(), [&act](int a, int b) {
			if (act[a].first == act[b].first)
				return act[a].second < act[b].second;
			else
				return act[a].first < act[b].first;
		});



		vector<char> res(n);
		bool ok = true;
		for (auto i : ind)
		{
			int s = act[i].first;
			//cout << "act " << i << " = " << s << " " << act[i].second << "\n";

			if (s >= av[0])
			{
				av[0] = act[i].second;
				res[i] = 'C';
				//cout << "to C\n";
			}
			else if (s >= av[1])
			{
				av[1] = act[i].second;
				res[i] = 'J';
				//cout << "to J\n";
			}
			else
			{
				ok = false;
				//cout << "error\n";
				break;
			}
		}


		cout << "Case #" << tti+1 <<": ";
		if (ok)
		{
			for (auto c : res)
				cout << c;
		}
		else
		{
			cout << "IMPOSSIBLE";
		}
		cout << "\n";
	
	}

	
    return 0;
}
