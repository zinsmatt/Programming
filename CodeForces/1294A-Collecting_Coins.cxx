// This is just a template solution used as initial script


#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)

#define VPRINT(name, v) \
	cout << name << " : "; \
	for (auto& e : v) { \
		cout << e << " "; \
	} \
	cout << std::endl; \

using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 


int main()
{
	ll tt, n;
	cin >> tt;
	F(t, tt)
	{
		ll a, b, c, n;
		cin >> a >> b >> c >> n;
		vector<ll> v = {a, b, c};
		sort(v.begin(), v.end());
		v[1] -= v[0];
		v[2] -= v[0];
		v[0] = 0;
		n -= (v[2] + v[2] - v[1]);
		if (n >= 0 && n % 3 == 0)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}


	cout << std::endl;

    return 0;
}
