#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;

using namespace std;


int main()
{

    int t;
    cin >> t;
    
    F(i, t)
    {
        string s;
        cin >> s;
        vector<bool> alpha(26, false);
        int j = 0;
        while (j < s.size())
        {
            char c = s[j];
            int count = 0;
            while (j < s.size() && s[j] == c)
            {
                ++count;
                ++j;
            }
            if (count % 2 == 1)
                alpha[c - 'a'] = true;
        }
        for (int j = 0; j < alpha.size(); ++j)
        {
            if (alpha[j])
            {
                cout << static_cast<char>('a' + j);
            }
        }
        cout << std::endl;
    }
    return 0;
}