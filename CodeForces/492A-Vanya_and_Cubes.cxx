#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;

using namespace std;


int main()
{
    int t = 1;
    
    F(i, t)
    {
        ll n;
        cin >> n;
        ll s = 0, j = 0, t = 0, count = 0;
        while (t <= n)
        {
            ++j;
            s += j;
            t += s;
            count++;
        }
        cout << count-1 << std::endl;
    }
    return 0;
}