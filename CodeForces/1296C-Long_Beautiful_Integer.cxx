#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
 
int main()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string res = s;
    for (int i = 0; i <k; ++i)
    {
        char ref = s[i];
        for (int j = i; j < s.size(); j += k)
        {
            res[j] = ref;
        }
    }
    int i = 0;
    while (i < s.size() && s[i] == res[i])
        ++i;

//cout << res << std::endl;
//cout << "i " << i << std::endl;
    if (i == s.size())
    {
        //good
    }
    else if (s[i] > res[i])
    {
        int j;
        if (i >= k)
        {
            j = k-1;

        }
        else
            j = i;
        while (j >= 0 && res[j] == '9')
            --j;
        //cout << "j = " << j << "\n";
        for (int i = j; i < res.size(); i += k)
            res[i]++;
        for (int i = j+1; i < k; ++i)
        {
            for (int l = i; l < res.size(); l += k)
                res[l] = '0';
        }
    }

    // else is already good i think

    cout << n << "\n";
    cout << res << "\n";
    return 0;
}