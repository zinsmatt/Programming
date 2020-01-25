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
		int n;
		cin >> n;
		vector<bool> map(n, false);
		int maxi = 0;
		vector<int> res(n);
		int a = 0;
		bool ok = true;
		F(i, n)
		{
			int x;
			cin >> x;
			if (x > maxi)
			{
				res[i] = x;
				map[x-1] = true;
				maxi = x;
			}
			else
			{
				while (a < n && map[a])
					++a;
				if (a >= n || a+1 > maxi)
				{
					ok = false;
				}
				else
				{
					map[a] = true;
					res[i] = a+1;
				}
			}
		}

		if (ok)
		{
			for (auto x : res)
				cout << x << " ";
			cout << std::endl;
		}
		else
		{
			cout << -1 << "\n";
		}

	}


	cout << std::endl;

    return 0;
}
