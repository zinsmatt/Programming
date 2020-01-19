#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;

using namespace std;


int main()
{
    int t;
    cin >> t;
    F(tt, t)
    {
    	ll n, s, k;
    	cin >> n >> s >> k;
    	vector<ll> above, below;
    	F(i, k)
    	{
    		int x;
    		cin >> x;
    		if (x >= s)
    		{
    			above.push_back(x-s);
    		}
    		else
    		{
    			below.push_back(s-x);
    		}
    	}
    	sort(above.begin(), above.end());
    	sort(below.begin(), below.end());


    	int a = 0;
    	while (a < above.size() && a == above[a])
    		++a;
    	int b = 1;
    	int i = 0;
    	while (i < below.size() && b == below[i])
    	{
    		++b;
    		++i;
    	}

    	if (s-b < 1)
    	{
    		cout << a << "\n";
    	}
    	else if (s+a > n)
    	{
    		cout << b << "\n";
    	}
    	else
    	{
    		cout << min(a, b) << std::endl;
    	}



    }
   
    
    return 0;
}