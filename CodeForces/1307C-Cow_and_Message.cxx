// This is just a template solution used as initial script


#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>     /* abs */

 
#define F(i, n) for (ll i = 0; i < n; ++i)

#define VPRINT(name, v) \
    cout << name << " : "; \
    for (auto& e : v) { \
        cout << e << " "; \
    } \
    cout << std::endl; \

using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 


int main()
{
    string s;
    cin >> s;

    vector<vector<ll>> tab(26, vector<ll>(26, 0));
    vector<ll> count(26, 0);

    if (s.size() == 1){
        cout << 1 << std::endl;
        return 0;
    }

    ll maxi = 0;
    for (auto& c : s)
    {
        F(i, 26)
        {
            tab[i][c-'a'] += count[i];
            if (tab[i][c-'a'] > maxi)
                maxi = tab[i][c-'a'];
        }
        ++count[c-'a'];
        if (count[c-'a'] > maxi)
            maxi = count[c-'a'];
    }
    cout << maxi << std::endl;


    return 0;
}
 