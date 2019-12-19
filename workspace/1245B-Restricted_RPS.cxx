#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 


int main()
{
    int t;
    cin >> t;
    F(tt, t)
    {
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string ss;
        cin >> ss;
        int r = 0, p = 0, s = 0;
        for (auto c : ss)
        {
            if (c == 'R') ++r;
            if (c == 'P') ++p;
            if (c == 'S') ++s;
        }
        int lim = (int)ceil((float)n/2);
        if (min(b, r) + min(c, p) + min(a, s) >= lim)
        {
            cout << "YES\n";
            string res = ss;

            for (auto& car : res)
            {
                if (car == 'R' && b > 0)
                {
                    car = 'P';
                    --b;
                }
                else if (car == 'P' && c > 0)
                {
                    car = 'S';
                    --c;
                }
                else if (car == 'S' && a > 0)
                {
                    car = 'R';
                    --a;
                }
                else
                {
                    car = '0';
                }
            }

            for (auto& car : res)
            {
                if (car == '0')
                {
                    if (a > 0)
                    {
                        car = 'R';
                        --a;
                    }
                    else if (b > 0)
                    {
                        car = 'P';
                        --b;
                    }
                    else if (c > 0)
                    {
                        car = 'S';
                        --c;
                    }
                }
            }
            cout << res << std::endl;
        }
        else
        {
            cout << "NO\n";
        }
    }

   
    return 0;
}
