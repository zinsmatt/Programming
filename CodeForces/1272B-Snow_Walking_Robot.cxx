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
        string s;
        cin >> s;
        int nl = 0, nr = 0, nu = 0, nd = 0;
        for (auto& c : s)
        {
            if (c == 'U')
                ++nu;
            else if (c == 'D')
                ++nd;
            else if (c == 'R')
                ++nr;
            else if (c == 'L')
                ++nl;
        }
        nd = min(nd, nu);
        nu = nd;
        nl = min(nl, nr);
        nr = nl;
        
        if (nr == 0)
        {
            nu = min(nu, 1);
            nd = nu;
        }
        else if (nu == 0)
        {
            nr = min(nr, 1);
            nl = nr;
        }
        std::cout << nr + nl + nu + nd << std::endl;
        F(i, nl)
            cout << "L";
        F(i, nu)
            cout << "U";
        F(i, nr)
            cout << "R";
        F(i, nd)
            cout << "D";
        
        std::cout << std::endl;
    }
   
 
   
    return 0;
}