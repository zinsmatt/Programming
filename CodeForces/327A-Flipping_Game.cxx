#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a, aa;
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        res += x;
        a.push_back(x);
        if (x == 1)
            aa.push_back(-1);
        else
            aa.push_back(1);
    }
    
    int cur = 0;
    int maxi = -1;
    for (int i = 0; i < n; ++i)
    {
        auto u = cur + aa[i];
        auto v = aa[i];
        if (u > v)
        {
            cur = u;
        }
        else
        {
            cur = v;
        }
        if (cur > maxi)
        {
            maxi = cur;
        }
    }
        
    cout << res + maxi << endl;
    
    return 0;
}