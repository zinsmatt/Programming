#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
 
int main()
{
    int n, sx, sy;
    cin >> n >> sx >> sy;
    int u=0, l=0, r=0, d=0;
    F(i, n)
    {
        int x, y;
        cin >> x >> y;
        if (x > sx)
            ++r;
        if (x < sx)
            ++l;
        if (y > sy)
            ++u;
        if (y < sy)
            ++d;
    }

    if (l >= r && l >= u && l >= d)
    {
        cout << l << "\n";
        cout << sx-1 << " " << sy << std::endl;
    }
    else if (r >= l && r >= u && r >= d)
    {
        cout << r << "\n";
        cout << sx+1 << " " << sy << std::endl;
    }else if (u >= l && u >= r && u >= d)
    {
        cout << u << "\n";
        cout << sx << " " << sy+1 << std::endl;
    }
    else if (d >= l && d >= r && d >= l)
    {
        cout << d << "\n";
        cout << sx << " " << sy-1 << std::endl;
    }
 

    
    return 0;
}