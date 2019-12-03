#include <iostream>
#include <bits/stdc++.h>

using namespace std;




int main()
{
    int t;
    cin >> t;
    string s;
    cin >> s;
    int i = 0;
    while (i < t - 1)
    {
        if (s[i+1] < s[i])
            break;
        ++i;
    }
    int remove_index = i;
    for (int i = 0; i < t; ++i)
    {
        if (i != remove_index)
            cout << s[i];
    }
    
    return 0;
}