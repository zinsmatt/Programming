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
    string s;
    cin >> s;
    int res = 0;
    F(i, t/2)
    {
        if (s[i*2] == s[i*2+1])
        {
            if (s[i*2] == 'a')
                s[i*2] = 'b';
            else
                s[i*2] = 'a';
            ++res;
        }
    }
    cout << res << "\n";
    cout << s << "\n";
   
    return 0;
}