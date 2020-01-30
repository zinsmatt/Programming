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

		int n;
		cin >> n;
		vector<int> v(n);
		F(i, n)
		{
			cin >> v[i];
		}
		int res = 0;
		int mini = v.back();
		for (int i = n-1; i >= 0; --i)
		{
			if (v[i] < mini)
				mini = v[i];
			if (v[i] > mini)
				++res;
		}
		cout << res << "\n";
	}



    return 0;
}
