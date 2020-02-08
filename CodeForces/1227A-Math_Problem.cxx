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
	ll tt;
	cin >> tt;
	F(t, tt)
	{
		ll n;
		cin >> n;
		ll largest_l = 0, smallest_r = 0;
		F(i, n)
		{
			int l, r;
			cin >> l >> r;
			if (l > largest_l)
				largest_l = l;
			if (smallest_r == 0 || r < smallest_r)
				smallest_r = r;
		}
		cout << max(0ll, largest_l - smallest_r) << std::endl;
	}
	
    return 0;
}
