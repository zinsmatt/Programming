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
    	string a, b;
    	cin >> a >> b;
    	if (a.size() > b.size())
    	{
    		cout << "NO\n";
    		continue;
    	}

    	int i = 0;
    	int k = 0;
    	bool ok = true;
    	while (i < a.size())
    	{
    		char c = a[i];
    		int j = i;
    		while (j < a.size() && a[j] == c)
    			++j;
    		int nb = j-i;

			int l = k;
			char cc = b[l];
			while (l < b.size() && b[l] == cc)
				++l;
			int nbnb = l-k;

			if (c != cc || nb > nbnb)
			{
				ok = false;
				break;
			}

			i = j;
			k = l;
    	}

    	if (ok && i == a.size() && k == b.size())
    	{
    		cout << "YES\n";
    	}
    	else
    	{
    		cout << "NO\n";
    	}

    }
   
    
    return 0;
}