#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;

using namespace std;


int main()
{
    int n;
    cin >> n;
    F(j, n)
    {
        string s, c;
        cin >> s >> c;
        int cur_min = s.back();
        int cur_mini = s.size() - 1;
        vector<int> mini(s.size());
        mini[s.size()-1] = s.size() - 1;
        for (int i = s.size() - 2; i >= 0; --i)
        {
            if (s[i] < cur_min)
            {
                cur_min = s[i];
                cur_mini = i;
            }
            mini[i] = cur_mini;
        }
        int i = 0;
        while (i < s.size() && (mini[i] == i || s[mini[i]] == s[i]))
            ++i;
        if (i < s.size())
        {
            swap(s[i], s[mini[i]]);
        }

        if (s < c)
            cout << s << "\n";
        else
            cout << "---" << std::endl;

    }
    
    return 0;
}