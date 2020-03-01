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
		vector<int> a(n);
		vector<bool> reste(2*n, true);
		F(i, n)
		{
			cin >> a[i];
			reste[a[i]-1] = false;
		}

		vector<int> res(2*n);
		bool ok = true;
		F(i, n)
		{
			auto x = a[i];
			int j = x;
			while (j < reste.size() && reste[j] == false) {
				++j;
			}
			if (j < reste.size())
			{
				res[2*i] = x;
				res[2*i+1] = j+1;
				reste[j] = false;
			}
			else
			{
				ok = false;
			}
		}
		
		if (ok)
		{
			for (auto x : res)
				cout << x << " ";
			cout << "\n";
		}
		else
		{
			cout << "-1\n";
		}
	}
	
    return 0;
}
