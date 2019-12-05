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
        string s;
        cin >> s;
        
        char car[] = {'a', 'b', 'c'};
        int map[33];
        std::fill(map, map+33, 0);
        map[11] = 2;
        map[12] = 3;
        map[13] = 2;
        map[21] = 3;
        map[22] = 3;
        map[23] = 1;
        map[31] = 2;
        map[32] = 1;
        map[33] = 2;
        int a = 0;
        bool ok = true;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i > 0 && s[i] == s[i-1])
            {
                ok = false;
                break;
            }
            if (s[i] != '?')
                continue;
            int l = -1;
            int r = -1;
            if (i > 0 && s[i-1] != '?')
            {
                l = 1 + s[i-1] - 'a';
            }
            if (i < s.size() - 1 && s[i+1] != '?')
            {
                r = 1 + s[i+1] - 'a';
            }
            if (l == -1 && r == -1)
            {
                l = 1;
                r = 1;
            }
            if (l == -1)
                l = r;
            if (r == -1)
                r = l;
            s[i] = car[map[r + 10 * l]-1];
        }
        if (ok)
            cout << s << std::endl;
        else
            cout << "-1" << std::endl;
    }
    return 0;
}