#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;

using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<bool> good(26, false);
    F(kk, k)
    {
        char c;
        cin >> c;
        good[c - 'a'] = true;
    }
    
    int l = -1;
    ull res = 0;
    F(i, n)
    {
        if (!good[s[i] - 'a'])
        {
            int size = max(0, i - l - 1);
            ull ullsize = size;
            l = i;
            res += ullsize*(ullsize+1)/2;
        }
    }
    int size = max(0, n - l - 1);
    ull ullsize = size;
    res += ullsize*(ullsize+1)/2;

   cout << res;
    return 0;
}