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
	ll n;
	cin >> n;
	vector<int> donne;
	vector<int> map(n+1, 0);
	vector<int> input(n+1, 0);
	F(i, n)
	{
		int x;
		cin >> x;
		map[x] = 1;
		input[i+1] = x;
		if (x == 0)
		{
			donne.push_back(i+1);
		}
	}

	vector<int> recoit(donne.size());
	int a = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (map[i] == 0)
			recoit[a++] = i;
	}

	//VPRINT("donne", donne)
	//VPRINT("recoit", recoit)
	//VPRINT("map", map)
	vector<int> d(donne.size());
	vector<int> r(donne.size());
	a = 0;
	for (auto p : donne)
	{
		if (map[p] == 0)
		{
			// gives and receives
			d[a] = p;
			r[(a+1)%donne.size()] = p;
			map[p] = -1;
			++a;
		}
	}

	//VPRINT("d", d)
	//VPRINT("r", r)
	//VPRINT("map", map)

	int b = (a+1) % donne.size();
	for (auto p : donne)
	{
		if (map[p] > 0)
		{
			d[a++] = p;
		}
	}

	//VPRINT("d", d)
	//VPRINT("r", r)
	//VPRINT("map", map)

	for (auto p : recoit)
	{
		if (map[p] == 0)
		{
			r[b] = p;
			b = (b+1) % donne.size();
		}
	}

	//VPRINT("d", d)
	//VPRINT("r", r)

	F(i, donne.size())
	{
		input[d[i]] = r[i];
	}

	for (int i = 1; i < input.size(); ++i)
	{
		cout << input[i] << " ";
	}
	cout << std::endl;

    return 0;
}
