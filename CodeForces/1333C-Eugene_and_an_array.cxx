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
	//cin >> tt;
	F(tti, tt)
	{ 
		ll n;
		cin >> n;
		vector<ll> a(n);
		int npos = 0, nneg = 0, nnul = 0;
		F(i, n){
			cin >> a[i];	
			if (a[i] < 0)
				nneg++;
			if (a[i] > 0)
				npos++;
			if (a[i] == 0)
				nnul++;
		} 
 
		if (npos == n || nneg == n)
		{
			cout << n * (n+1) / 2 << "\n";
			return 0;
		}

		unordered_map<ll, int> prev;
		prev[0] = -1;
		ll cum = 0;
		int cur = 0;
		ll res = 0;
		F(i, n)
		{
			//cout << "i = " << i << "\n";
			cum += a[i];
			//cout << "cum = " << cum << "\n";

			if (prev.find(cum) != prev.end())
			{
				cur = max(cur, prev[cum] + 2);
			}
			prev[cum] = i;

			//cout << "cur = " << cur << "\n";
			//cout << "====> add " << i - cur + 1 << "\n";
			res += i - cur + 1;
		}



		cout << res << "\n";
	}

    return 0;
}
