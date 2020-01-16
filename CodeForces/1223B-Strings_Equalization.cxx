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
        string s, p;
        cin >> s >> p;
        vector<bool> dico(26, false);
        for (auto&c : s)
        {
            dico[c - 'a'] = true;
        }

        bool ok = false;
        for (auto c : p)
        {
            if (dico[c - 'a'])
            {
                ok = true;
                break;
            }
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";


    }

    return 0;
}
