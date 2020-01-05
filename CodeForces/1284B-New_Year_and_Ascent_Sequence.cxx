#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#define F(i, n) for (ll i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;




int main()
{
    ll n;
    cin >> n;
    //vector<pair<int, int>> good;
    vector<int> b, e;
    F(i, n)
    {
        int l;
        cin >> l;
        vector<int> s(l);
        bool ok = true;
        F(j, l)
        {
            cin >> s[j];
            if (j > 0 && s[j] > s[j-1])
            {
                ok = false;
            }
        }
        if (ok)
        {
            //good.push_back(std::make_pair(s.front(), s.back()));
            b.push_back(s.front());
            e.push_back(s.back());
            //cout << "add " << s.front() << " " << s.back() << std::endl;
        }
    }

    unordered_map<int, int> map;
    sort(e.begin(), e.end());
    vector<int> count(1e6+1, 0);
    F(i, e.size())
    {
        count[e[i]]++;
    }

    for (int i = count.size()-1; i >= 0; --i)
    {
        count[i] = count[i+1] + count[i];
    }

    ll res = 0;
    F(i, b.size())
    {
        res += count[b[i]];
    }
    res = n*n - res;
    cout << res << "\n";
   
    return 0;
}