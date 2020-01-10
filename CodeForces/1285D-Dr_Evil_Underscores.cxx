#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
vector<int> bin(int x)
{
    std::vector<int> v(32, 0);
    int i = 0;
    while (x > 0)
    {
        int r = x % 2;
        v[i++] = r;
        x = (x - r) / 2;
    }
    reverse(v.begin(), v.end());
    return v;
}

int res = std::numeric_limits<int>::max();

void solve(vector<vector<int>>& map, const vector<int> &idx, int it, int cur)
{
   
    if (it < 32)
    {
        vector<int> aa, bb;
        for (auto i : idx)
        {
            if (map[i][it] == 0)
                aa.push_back(i);
            else
                bb.push_back(i);
        }
        if (aa.size() == 0 || bb.size() == 0)
            solve(map, idx, it+1, cur);
        else
        {
            if (aa.size() > 0)
            {
                solve(map, aa, it+1, cur + pow(2, 31-it));
            }


            if (bb.size() > 0)
            {
                solve(map, bb, it+1, cur + pow(2, 31-it));
            }

        }
    }
    else
    {
        res = min(res, cur);
    }
}

int main()
{
    ll n;
    cin >> n;
    vector<vector<int>> a(n);
    F(i, n)
    {
        int x;
        cin >> x;
        a[i] = bin(x);
    }

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    solve(a, idx, 0, 0);
    cout << res << "\n";
    
    return 0;
}