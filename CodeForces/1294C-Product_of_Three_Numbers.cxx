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
		ll n;
		cin >> n;
		vector<int> div;
		int a = 0, b = 0, c = 0;
		for (int i = 2; i < sqrt(n); ++i)
		{
			if (n % i == 0)
			{
				int x = i;
				a = n / x;
				//cout << "test a = " << a << " x = " << x << "\n";
				for (int j = 2; j < sqrt(x); ++j)
				{
					if (x % j == 0 && j*j != x && j != a && x / j != a)
					{
						b = j;
						c = x / j;
					}
				}

				if (a*b*c == n)
				{
					break;
				}

				x = n / x;
				a = n / x;
				//cout << "test a = " << a << " x = " << x << "\n";

				for (int j = 2; j < sqrt(x); ++j)
				{
					//cout << "j = " << j << "\n";
					//cout << "j*j jj x / j " << j*j << " " << j << " " << x/j << "\n";
					if (x % j == 0 && j*j != x && j != a && x / j != a)
					{
						b = j;
						c = x / j;
						//cout << "=> b c = " << b << " " << c << std::endl;
					}
				}

				if (a*b*c == n)
				{
					break;
				}
			}
		}
		if (a*b*c == n && a != b && a != c && b != c)
		{
			cout << "YES\n" << a << " " << b << " " << c << "\n";
		}
		else
		{
			cout << "NO\n";
		}
	}


	cout << std::endl;

    return 0;
}
