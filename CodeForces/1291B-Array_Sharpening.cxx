// This is just a template solution used as initial script


#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>     /* abs */

 
#define F(i, n) for (ll i = 0; i < n; ++i)

#define VPRll(name, v) \
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
	ll tt;
	cin >> tt;
	F(t, tt)
	{
		ll n;
		cin >> n;
		vector<ll> a(n);
		F(i, n)
			cin >> a[i];
		int i = 0;
		while (i < n && a[i] >= i)
			++i;
		--i;	// last good
		if (i == n-1)
		{
			cout << "Yes\n";
			continue;
		}
		else
		{
			int j = n-1;
			while (j >= 0 && a[j] >= n-1-j)
				--j;
			++j; // last good
			if (j <= i)
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}

    return 0;
}
