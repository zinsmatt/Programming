#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 


int main()
{
	ll n, q;
	cin >> n >> q;
	vector<vector<bool>> map(2, vector<bool>(n+1, true));
	int nb = 0;

	F(i, q)
	{
		int x, y;
		cin >> y >> x;

		map[y-1][x] = !map[y-1][x];

		if (map[y-1][x] == true)
		{
			if (x > 1 && map[(y-1+1) % 2][x-1] == false)
				--nb;
			if (map[y%2][x] == false)
				--nb;
			if (x < n && map[(y-1+1)%2][x+1] == false)
				--nb;
		}
		else
		{
			if (x > 1 && map[(y-1+1) % 2][x-1] == false)
				++nb;
			if (map[y%2][x] == false)
				++nb;
			if (x < n && map[(y-1+1)%2][x+1] == false)
				++nb;
		}


		if (nb == 0)
			cout << "Yes\n";
		else
			cout << "No\n";
	}


    return 0;
}
