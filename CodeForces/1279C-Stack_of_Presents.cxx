#include <iostream>
#include <bits/stdc++.h>
#include <queue>
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
        ll n, m;
        cin >> n >> m;

        vector<ll> a(n), b(m);
        F(i, n)
            cin >> a[i];
        F(i, m)
            cin >> b[i];

        unordered_map<int, int> map;
        F(i, n)
        {
            map[a[i]] = i;
        }

        int cur = -1;
        int nb_removed = 0;
        ll res = 0;
        int sorted = -1;
        for (auto x : b)
        {
            int pos = map[x];
            if (pos > cur)
            {
                int k = max(0, map[x] - nb_removed);
                res += 2 * k + 1;
                cur = pos;
            }
            else
            {
                res++;
            }
            nb_removed++;
        }
        cout << res << "\n";

    }
    return 0;
}