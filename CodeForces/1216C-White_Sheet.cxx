#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 

int x1, yy1, x2, y2; 
int x3, y3, x4, y4;
int x5, y5, x6, y6;

bool inside_b1(float x, float y)
{
    return x <= x4 && x >= x3 && y <= y4 && y >= y3;
}

bool inside_b2(float x, float y)
{
    return x <= x6 && x >= x5 && y <= y6 && y >= y5;
}

int main()
{

    cin >> x1 >> yy1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;

    bool ok = false;
    if (!inside_b1(x1, yy1) && !inside_b2(x1, yy1))
    {
        cout << "YES";
        return 0;
    }

    if (!inside_b1(x1, y2) && !inside_b2(x1, y2))
    {
        cout << "YES";
        return 0;
    }
     
    if (!inside_b1(x2, y2) && !inside_b2(x2, y2))
    {
        cout << "YES";
        return 0;
    }
     
    if (!inside_b1(x2, yy1) && !inside_b2(x2, yy1))
    {
        cout << "YES";
        return 0;
    }
     
    for (float x = x1; x <= x2; x += 0.5)
    {
        if (!inside_b1(x, yy1) && !inside_b2(x, yy1))
        {
            cout << "YES";
            return 0;
        }
    }

    for (float y = yy1; y <= y2; y += 0.5)
    {
        if (!inside_b1(x1, y) && !inside_b2(x1, y))
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
   
    return 0;
}
