#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;

using namespace std;


int main()
{
    string s;
    cin >> s;
    int l = 0, r = s.size() - 1;
    int total = 0;
    bool ok = true;
    
    while (l < r)
    {
        char cur = s[l];
        int cl = 0;
        while (l < r && s[l] == cur)
        {
            ++l;
            ++cl;
        }

        int cr = 0;
        while (r > l && s[r] == cur)
        {
            --r;
            ++cr;
        }

        if (l == r)
        {
            if (s[r] == cur)
                total = cr + cl + 1;
            else
                ok = false;
        }
        else
        {
            if (cr > 0 && cl > 0 && cl + cr >= 3)
            {
                // good
            }
            else
            {
                ok = false;
                break;
            }
        }
    }
    if (!ok)
    {
        cout << "0\n";
    }
    else
    {
        if (total >= 2)
            cout << total + 1 << std::endl;
        else
            cout << 0 << std::endl;
    }
   
    
    return 0;
}