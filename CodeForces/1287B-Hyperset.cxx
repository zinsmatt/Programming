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

    unordered_map<string, int> map;
    vector<string> a(n);

    F(i, n)
    {
        string s;
        cin >> s;
        a[i] = s;
        map[s] = i;
    }

    int res = 0;
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            string search;
            search.resize(k);

            for (int o = 0; o < k; ++o)
            {
                if (a[i][o] == a[j][o])
                {
                    search[o] = a[i][o];
                }
                else
                {
                    if (a[i][o] != 'S' && a[j][o] != 'S')
                        search[o] = 'S';
                    else if (a[i][o] != 'E' && a[j][o] != 'E')
                        search[o] = 'E';
                    else if (a[i][o] != 'T' && a[j][o] != 'T')
                        search[o] = 'T';
                }
            }
            if (map.find(search) != map.end() && map[search] > j)
            {
                ++res;
            }
        }
    }
    cout << res << "\n";
   
    return 0;
}
