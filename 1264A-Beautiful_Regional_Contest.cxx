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
        int n;
        cin >> n;

        vector<int> a(n);
        int lim = n / 2;
        // cout << "lim = " << lim << std::endl;
    
        unordered_map<int, int> map;
        vector<int> keys;
        F(j, n)
        {
            cin >> a[j];
        };
        
        if (n < 3)
        {
            cout << "0 0 0\n";
            continue;
        }
        int last = lim;
        while (last >=0 && a[last] == a[lim])
            --last;
        for (int j = 0; j <= last; ++j)
        {
            if (map.find(a[j]) != map.end())
            {
                map[a[j]]++;
            }
            else
            {
                map[a[j]] = 1;
                keys.push_back(a[j]);
            }
        }
        int g = 0, b = 0, s = 0;
        if (keys.size() > 0)
        {
            g = map[keys[0]];
            s = 0;
            int k = 1;
            while (k < keys.size() && s <= g)
            {
                s += map[keys[k]];
                ++k;
            }
            b = last + 1 - g - s;

            if (b == 0 || b <= g)
            {
                g = 0;
                s = 0;
                b = 0;
            }
        }
        cout << g << " " << s << " " << b << std::endl;

    }
    return 0;
}