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
	F(t, tt)
	{
		ll n;
		cin >> n;
		vector<int> a(n);

		F(i, n)
		{
			cin >> a[i]; --(a[i]);
		}
		vector<bool> done(n);
		int maxi = *max_element(a.begin(), a.end());
		set<int> res;

		bool left_ok = true;
		vector<int> ok(maxi+1, false);
		F(i, ok.size())
		{
			if (a[i] < ok.size())
				ok[a[i]] = true;
			else {
				left_ok = false;
				break;
			}
		}
		if (left_ok)
			left_ok	 = accumulate(ok.begin(), ok.end(), 0) == ok.size();

		bool right_ok = true;
		if (left_ok)
		{
			vector<int> ok(n-maxi-1, false);
			F(i, ok.size())
			{
				if (a[n-1-i] < ok.size())
					ok[a[n-1-i]] = true;
				else {
					right_ok = false;
					break;
				}
			}
			if (right_ok)
				right_ok = accumulate(ok.begin(), ok.end(), 0) == ok.size();
		}

		if (left_ok && right_ok)
		{
			res.insert(maxi+1);
		}

		//-------------

		reverse(a.begin(), a.end());

		//----------------
		left_ok = true;
		vector<int> ok2(maxi+1, false);
		F(i, ok.size())
		{
			if (a[i] < ok2.size())
				ok2[a[i]] = true;
			else {
				left_ok = false;
				break;
			}
		}
		if (left_ok)
			left_ok	 = accumulate(ok2.begin(), ok2.end(), 0) == ok2.size();

		right_ok = true;
		if (left_ok)
		{
			vector<int> ok(n-maxi-1, false);
			F(i, ok.size())
			{
				if (a[n-1-i] < ok.size())
					ok[a[n-1-i]] = true;
				else {
					right_ok = false;
					break;
				}
			}
			if (right_ok)
				right_ok = accumulate(ok.begin(), ok.end(), 0) == ok.size();
		}

		if (left_ok && right_ok)
		{
			res.insert(n-maxi-1);
		}

		if (res.size() == 0)
		{
			cout << "0\n";
		}
		else
		{
			cout << res.size() << "\n";
			for (auto x : res)
			{
				cout << x << " " << n-x << "\n";

			}
		}

	}

	
    return 0;
}
