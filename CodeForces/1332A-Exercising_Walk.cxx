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



int main()
{
	ll tt;
	cin >> tt;
	F(t, tt)
	{
		ll a, b, c, d;
		ll x, y, x0, x1, y0, y1;
		cin >>a>> b>> c>> d;
		cin >> x>> y>> x0>>  y0>> x1>>y1;

/*
		cout << x1 - x << " " <<  b-a  << "\n";
		cout << x - x0 << " " <<  a-b  << "\n";
		cout << y1 - y << " " <<  d-c  << "\n";
		cout << y - y0 << " " <<  c-d  << "\n";*/
		ll r = x1-x;
		ll l = x-x0;
		bool ok = false;
		if (b-a == 0)
		{
			if (r > 0 || l > 0 || a == 0)
			{
				ok = true;
			}
		}
		else if (b-a > 0)
		{
			if (b-a <= r)
				ok = true;
		}
		else if (a-b > 0)
		{
			if (a-b <= l)
				ok = true;
		}


		ll h = y1-y;
		ll bb = y-y0;
		bool ok2 = false;
		if (d-c == 0)
		{
			if (h > 0 || bb> 0 || c == 0)
			{
				ok2 = true;
			}
		}
		else if (d-c > 0)
		{
			if (d-c <= h)
				ok2 = true;
		}
		else if (c-d > 0)
		{
			if (c-d <= bb)
				ok2 = true;
		}



		if (ok && ok2)
		{
			cout << "Yes\n";
		}
		else
			cout << "No\n";

	}


    return 0;
}