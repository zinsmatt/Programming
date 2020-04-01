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
	
	int h, w;
	cin >> h >> w;
	vector<vector<bool>> map(h, vector<bool>(w, false));
	int n = 0;
	int x = -1, y = -1;
	F(i, h)
	{
		F(j, w)
		{
			char x;
			cin >> x;
			map[i][j] = (x == '*') ? true : false;
			if (x == '*')
				++n;

		}
	}

	bool ok = true;
	for (int i = 1; i < h-1; ++i)
	{
		for (int j = 1; j < w-1; ++j)
		{
			if (map[i][j] && map[i-1][j] && map[i+1][j] &&
				map[i][j-1] && map[i][j+1])
			{
				if (x == -1 && y == -1)
				{
					x = j;
					y = i;
				}
				else
				{
					cout << "NO\n";
					return 0;
				}
			}

		}
	}

	if (x == -1 && y == -1)
	{
		cout << "NO\n";
		return 0;
	}
	int k = 0;
	for (int i = y+1; i+1 < h; ++i)
	{
		if (!map[i][x] && map[i+1][x])
		{
			cout << "NO\n";
			return 0;
		}
		k += map[i+1][x];
	}

	for (int i = y-1; i-1 >= 0; --i)
	{
		if (!map[i][x] && map[i-1][x])
		{
			cout << "NO\n";
			return 0;
		}
		k += map[i-1][x];
	}


	for (int j = x+1; j+1 < w; ++j)
	{
		if (!map[y][j] && map[y][j+1])
		{
			cout << "NO\n";
			return 0;
		}
		k += map[y][j+1];
	}

	for (int j = x-1; j-1 >= 0; --j)
	{
		if (!map[y][j] && map[y][j-1])
		{
			cout << "NO\n";
			return 0;
		}
		k += map[y][j-1];
	}

	if (k + 5 == n)
		cout << "YES\n";
	else
		cout << "NO\n";

    return 0;
}
