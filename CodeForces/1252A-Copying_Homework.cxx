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
	F(i, n)
	{
		int x;	
		cin >> x;
		cout << n-x+1 << " ";
	}
	cout << "\n";

    return 0;
}
