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
        ll n, g, b;
        cin >> n >> g >> b;
        ll nb_g = (ll)ceil((double)n / 2);
        if (g >= b)
        {
            cout << n << std::endl;
        }
        else
        {
            ll res = max(0ll, ((ll)ceil((double)nb_g / g) - 1)) * b + nb_g;
            cout <<  res + max(0ll, n - res) << std::endl;
        }
    }

    return 0;
}
