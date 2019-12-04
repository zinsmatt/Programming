
#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;

using namespace std;


int main()
{
    int t;
    cin >> t;
    
    F(i, t)
    {
        int x, y;
        cin >> x >> y;
        if (x >= y)
            cout << "YES\n";
        else
        {
            if (x == 1 || (x <= 3 && y > 3))
                cout << "NO\n";
            else
                cout << "YES\n";
        }
        
    }
    return 0;
}