#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 


int main()
{
    int t;
    cin >> t;

    vector<vector<int>> dig(10);
    for (int i = 0; i <= 9; ++i)
    {
        int x = i;
        vector<int> res = {x};
        x = (x + i) % 10;
        while (x != i)
        {
            res.push_back(x);
            x = (x + i) % 10;
        }
        dig[i] = res;
    }

    F(tt, t)
    {
        ull n, m;
        cin >> n >> m;
        ull N = static_cast<ull>(n/m);

        int d = m % 10;

        ull nn = N / dig[d].size();
        ull rr = N % dig[d].size();
        ull sum = 0;
        for (int j = 0; j < dig[d].size(); ++j)
        {
            if (j < rr)
            {
                sum += (nn + 1ull) * dig[d][j];
            }
            else
            {
                sum += nn * dig[d][j];
            }
        }
        cout << sum << "\n";
    }


    return 0;
}
