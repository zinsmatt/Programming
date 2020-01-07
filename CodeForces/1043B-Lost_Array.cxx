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
    vector<int> a(n, 0);
    int prev = 0;
    F(i, n)
    {
        int x;
        cin >> x;
        a[i] = x - prev;
        prev = x;
    }

    vector<int> res;
    for (int x = 1; x < n; ++x)
    {
        if (a[x] == a[0])
        {
            int l = 0, r = x;
            bool ok = true;
            while (r < n)
            {
                if (a[r] != a[l])
                {
                    ok = false;
                    break;
                }
                else
                {
                    ++r;
                    ++l;
                }
            }
            if (ok)
            {
                res.push_back(x);
            }
        }
    }
    res.push_back(n);
    cout << res.size() << "\n";
    for (auto r : res) cout << r << " ";
    cout << "\n";
   
    return 0;
}
