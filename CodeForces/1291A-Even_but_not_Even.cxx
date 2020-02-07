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
		string s;
		cin >> s;
		string res;
		for (int k = 0; k < n; ++k)
		{
			if ((s[k] - '0')%2 == 1)
			{
				if (res.size() < 2)
					res += s[k];
			}
		}
		if (res.size() == 2)
			cout << res << "\n";
		else
			cout << "-1\n";
	}

    return 0;
}
