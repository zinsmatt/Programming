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
		vector<pair<int, int>> coords(n, pair<int, int>(0, 0));
		int maxi = 0;
		F(i, n)
		{
			int x, y;
			cin >> x >> y;
			coords[i].first = x;
			coords[i].second = y;
		}
	
		std::sort(coords.begin(), coords.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
			if (a.first < b.first)
				return true;
			else if (a.first == b.first)
				return a.second < b.second;
			else
				return false;
		});


		int x = 0, y = 0;
		stringstream res;
		bool ok = true;
		for (const auto& p : coords)
		{
			int dx = p.first - x;
			int dy = p.second - y;
			if (dx < 0 || dy < 0)
			{
				ok = false;
				break;
			}
			F(j, dx)
				res << "R";
			F(j, dy)
				res << "U";
			x = p.first;
			y = p.second;
		}

		if (ok)
			cout << "YES\n" << res.str() << "\n";
		else
			cout << "NO\n";

	}


	cout << std::endl;

    return 0;
}
