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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	stringstream left, right;
	while (a > 0)
	{
		left << "0";
		--a;
		if (b > 0)
		{
			left << "1";
			--b;
		}
		else
		{
			break;
		}
	}
	string sl = left.str();
	if (sl.size() > 0 && sl.back() == '0' && (c > 0 || d > 0))
	{
		cout << "NO\n";
		return 0;
	}

	while (d > 0)
	{
		right << "3";
		--d;
		if (c > 0)
		{
			right << "2";
			--c;
		}
		else
		{
			break;
		}
	}
	string sr = right.str();
	if (sr.size() > 0 && sr.back() == '3' && (sl.size() > 0 || b > 0))
	{
		cout << "NO\n";
		return 0;
	}

	int m = min(b, c);
	stringstream inter;
	F(i, m)
	{
		inter << "21";
		--b;
		--c;
	}

	if (b > 0)
	{
		sl = "1" + sl;
		--b;
	}
	if (c > 0)
	{
		sr = "2" + sr;
		--c;
	}

	if (a > 0 || b > 0 || c > 0 || d > 0)
	{
		cout << "NO\n";
		return 0;
	}

	reverse(sr.begin(), sr.end());
	cout << "YES\n";
	for (auto& c : sl + inter.str() + sr)
		cout << c << " ";
	cout << "\n";

    return 0;
}
