#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
 
int main()
{
    ll n;
    cin >> n;
    if (n % 2 == 0)
        cout << n+4 << " " << 4 << std::endl;
    else
        cout << n+9 << " " << 9 << std::endl;
   
    return 0;
}