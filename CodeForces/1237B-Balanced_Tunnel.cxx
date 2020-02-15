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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	unordered_map<int, int> map;
	vector<int> c(n);
	F(i, n){
		cin >> a[i];		
		//map[a[i]] = (i > 0) ? a[i-1] : 0;
		map[a[i]] = i;
	}
		
	F(i, n){
		cin >> b[i];
		map[b[i]] = i;
	}

	F(i, n)
	{
		c[i] = map[a[i]];
	}
		
	int maxi = 0;
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		if (c[i] < maxi)
			++res;
		maxi = max(c[i], maxi);
	}
	

	cout << res << std::endl;
	
    return 0;
}
