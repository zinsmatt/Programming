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
	string s;
	cin >> s;
	int i = s.size()-1;
	while (i >=0)
	{
		if (s[i] == 'a')
			break;
		--i;
	}
	if (i < 0)
	{
		// no a
		if (s.size() % 2 == 0)
		{
			if (s.substr(0, s.size()/2) == s.substr(s.size()/2, s.size()/2))
				cout << s.substr(0, s.size()/2) << "\n";
			else
				cout << ":(\n";
		}
		else
			cout << ":(\n";
	}
	else if (i == s.size() - 1)
	{
		for (auto c : s)
		{
			if (c != 'a')
			{
				cout << ":(\n";
				return 0;
			}
		}
		cout << s << "\n";
	}
	else
	{
		int nb=0;
		for (int j = 0; j <= i; ++j)
		{
			if (s[j] != 'a')
				nb++;
		}
		int nr = s.size() - i - 1;


		if (nb > nr)
		{
			cout << ":(\n";
			return 0;
		}
		else if ((nr - nb) % 2 == 0)
		{
			i += (nr - nb) / 2;
			//cout << "n = " << s.size() << "\n";
			//cout << "s = " << i << std::endl;
			//cout << "s1 = " << s.substr(0, i+1) << "\n";
			//cout << "s2 = " << s.substr(i+1, s.size()-(i+1)-1) << "\n";
			int a = 0, b = i+1;
			for (int a = 0; a <= i; ++a)
			{
				if (s[a] != 'a')
				{
					if (b >= s.size() || s[b] != s[a])
					{
						cout << ":(\n";
						return 0;
					}
					else
					{
						++b;
					}
				}
			}
			cout << s.substr(0, i+1) << "\n";
		}
		else
		{
			cout << ":(\n";
			return 0;
		}
	}


    return 0;
}
