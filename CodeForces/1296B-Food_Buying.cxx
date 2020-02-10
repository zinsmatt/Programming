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
 
ll powll(ll x, ll p)
{
	if (p == 0)
		return 1;
	else
		return powll(x, p-1) * x;
}


int main()
{
    ll tt;
    cin >> tt;
    F(t, tt)
    {
        ll x;
        cin >> x;
        ll res = 0;
        while (x >= 10)
        {
            ll r = x % 10;
            res += x - r;

            x = r + (x - r) / 10;
        }
        res += x;
        cout << res << std::endl;
    }

    return 0;
}
