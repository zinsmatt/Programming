#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;

using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    F(k, n)
    {
        cin >> a[k];
    }
    
    vector<int> l(n, 1);
    vector<int> r(n, 1);
    int maxi = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i-1] < a[i])
        {
            l[i] = l[i-1] + 1;
        }
        if (l[i] > maxi)
            maxi = l[i];
    }
    
    for (int i = n-2; i >= 0; --i)
    {
        if (a[i] < a[i+1])
        {
            r[i] = r[i+1] + 1;
        }
    }
    
    for (int i = 2; i < n-1; ++i)
    {
        if (a[i-1] < a[i+1])
        {
            maxi = max(maxi, l[i-1] + r[i+1]);
        }
    }


    cout << maxi;
    
    
    return 0;
}