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
        int n;
        cin >> n;
        vector<int> p(1+n);
        for (int j = 1; j <= n; ++j)
        {
            cin >> p[j];
        }
        for (int j = 1; j <= n; ++j)
        {
            int c = 0;
            int idx = j;
            while (c == 0 || idx != j)
            {
                ++c;
                idx = p[idx];
            }
            cout << c << " ";
        }
        cout << std::endl;
        
    }
   
 
   
    return 0;
}