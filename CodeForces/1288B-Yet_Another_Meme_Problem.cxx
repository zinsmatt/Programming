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
        ll A, B;
        cin >> A >> B;
        ll mini = floor(log10(B));
        if (std::pow(10ll, mini+1)-1 == B)
            mini++;
        cout << A * mini << std::endl;
    }

    return 0;
}
