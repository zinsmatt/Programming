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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll i = 0, j = n-1;
        while (i <= j && s[i] == '0' && s[j] == '0')
        {
            ++i;
            --j;        
        }
        if (i <= j)
        {
            cout << (n-i)*2 << endl;
        }
        else
        {
            cout << n << std::endl;
        }
    }

    return 0;
}
