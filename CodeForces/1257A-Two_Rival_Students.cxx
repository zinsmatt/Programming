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
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        cout << min(n-1, abs(a-b)+x) << "\n";
    }
    return 0;
}