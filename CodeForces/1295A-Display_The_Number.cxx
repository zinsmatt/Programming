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
        stringstream ss;
        F(i, x/2)
            ss << "1";
        auto res = ss.str();
        if (x % 2 == 1)
            res[0] = '7';
        cout << res << std::endl;
    }

    return 0;
}
