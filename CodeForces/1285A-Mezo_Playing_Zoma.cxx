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
    string s;
    cin >> s;
    int l = 0, r = 0;

    for (auto c : s)
    {
        if (c == 'L')
            ++l;
        else
            ++r;
    }
    ll res = 1 + r + l;
    cout << res << "\n";
    

    return 0;
}