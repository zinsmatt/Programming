#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;

using namespace std;


int main()
{
    int t;
    cin >> t;
    F(tt, t)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << max(0, abs(a-b)+abs(b-c)+abs(a-c)-4) << "\n";
        
    }
   
 
   
    return 0;
}