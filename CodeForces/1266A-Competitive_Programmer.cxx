#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
 
int main()
{
    ll n;
    cin >> n;
    F(tt, n)
    {
        string s;
        cin >> s;
        int n0 = 0;
        int n_pairs = 0;
        int sum_digits = 0;
        for (auto c : s)
        {
            if (c == '0')
                ++n0;
            int x = c - '0';
            if (x % 2 == 0)
                ++n_pairs;
            sum_digits += x;
        }
        if (sum_digits % 3 == 0 && n0 >= 1 && n_pairs >= 2)
        {
            cout << "red" << std::endl;
        }
        else
        {
            cout << "cyan" << std::endl;
        }

        
    }
   
    return 0;
}