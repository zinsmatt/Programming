#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 


int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n == 1)
    {
        if (k > 0)
            s[0] = '0';
    }
    else
    {
        if (k > 0)
        {
            if (s[0] != '1')
            {
                s[0] = '1';
                --k;            
            }
        }
        for (int i = 1; i < n && k > 0; ++i)
        {
            if (s[i] != '0')
            {
                s[i] = '0';
                --k;
            }
        }
    }
    cout << s << std::endl;


    return 0;
}
